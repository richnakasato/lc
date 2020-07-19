/*
plan: topological sort with cycle detection
time: V + E
space: V + E?
*/

class Solution {
public:
    void hydrate_structures(int num_courses,
                            const vector<vector<int>>& prerequisites,
                            unordered_map<int,vector<int>>& graph,
                            unordered_set<int>& starts) {
        for (auto i=0; i<num_courses; ++i) {
            graph[i] = vector<int>{};
            starts.insert(i);
        }
        for (auto course : prerequisites) {
            graph[course[1]].push_back(course[0]);
            if (starts.find(course[0]) != starts.end()) starts.erase(course[0]);
        }
        return;
    }
    bool dfs(unordered_map<int,vector<int>>& graph,
             int course,
             unordered_set<int>& parents,
             unordered_set<int>& completed,
             list<int>& order) {
        // assume course is in graph
        parents.insert(course);
        for (auto val : graph[course]) {
            if (parents.find(val) != parents.end()) return false;
            if (completed.find(val) != completed.end()) continue;
            if (!dfs(graph, val, parents, completed, order)) return false;
        }
        parents.erase(course);
        completed.insert(course);
        order.push_front(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // empty case
        auto result = vector<int>{};
        if (!numCourses) return result;

        // create data structures
        auto prereqs = unordered_map<int,vector<int>>{};
        auto starts = unordered_set<int>{};
        hydrate_structures(numCourses, prerequisites, prereqs, starts);

        // check if possible
        if (!size(starts)) return result;

        // traverse starts
        auto order = list<int>{};
        auto completed = unordered_set<int>{};
        for (auto start : starts) {
            auto parents = unordered_set<int>{};
            if (!dfs(prereqs, start, parents, completed, order)) return result;
        }

        // have all courses been taken?
        if (size(order) < numCourses) return result;

        // copy to result
        for (auto item : order) {
            result.push_back(item);
        }
        return result;
    }
};
