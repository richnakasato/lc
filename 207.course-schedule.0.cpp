/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (35.63%)
 * Total Accepted:    167.5K
 * Total Submissions: 470.2K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */
class Solution {
public:
    std::vector<std::vector<int>> graph_builder(
            int num_courses,
            const std::vector<std::vector<int>>& reqs) {
        std::vector<std::vector<int>> adj_list(num_courses,
                                               std::vector<int>());
        for (auto& pair : reqs) {
            auto src_node = pair[1];
            auto dest_node = pair[0];
            adj_list[src_node].push_back(dest_node);
        }
        return adj_list;
    }
    bool cycle_detect(int curr,
                      const std::vector<std::vector<int>>& adj_lists,
                      std::vector<bool>& visited) {
        if (visited[curr]) return true;
        visited[curr] = true;
        for (int i=0; i<adj_lists[curr].size(); ++i) {
            int next = adj_lists[curr][i];
            if (cycle_detect(next, adj_lists, visited)) return true;
        }
        visited[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (!numCourses) return true;
        if (prerequisites.empty()) return true;
        auto adj_list = graph_builder(numCourses, prerequisites);
        for (auto i=0; i<adj_list.size(); ++i) {
            std::vector<bool> visited(numCourses, false);
            if (cycle_detect(i, adj_list, visited)) return false;
        }
        return true;
    }
};
