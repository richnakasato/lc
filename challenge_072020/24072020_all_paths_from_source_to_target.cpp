/*
 plan: dfs to target, track nodes until hit target or no more nodes, remember to backtrack
 time: linear wrt v + e
 space: linear wrt v + e
 */

class Solution {
public:
    void dfs(const vector<vector<int>>& graph,
             int curr,
             const int& target,
             vector<int>& path,
             vector<vector<int>>& paths) {
        path.push_back(curr);
        if (curr == target) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for (auto dest : graph[curr]) {
            dfs(graph, dest, target, path, paths);
        }
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        auto paths = vector<vector<int>>{};
        if (!size(graph)) return paths;
        auto source = 0;
        auto target = size(graph) - 1;
        auto path = vector<int>{};
        dfs(graph, source, target, path, paths);
        return paths;
    }
};
