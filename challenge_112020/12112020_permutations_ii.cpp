class Solution {
public:
    void dfs(const vector<int>& nums,
             vector<bool>& used,
             int idx,
             vector<int>& curr,
             set<vector<int>>& results) {
        curr.push_back(nums[idx]);
        used[idx] = true;
        if (size(curr) == size(nums)) results.insert(curr);
        else {
            for (int i=0; i<size(nums); ++i) {
                if (!used[i]) dfs(nums, used, i, curr, results);
            }
        }
        used[idx] = false;
        curr.pop_back();
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (!size(nums)) return vector<vector<int>>{};
        auto used = vector<bool>(size(nums),false);
        auto curr = vector<int>{};
        auto results = set<vector<int>>{};
        for (int i=0; i<size(nums); ++i) {
            dfs(nums, used, i, curr, results);
        }
        auto perms = vector<vector<int>>{};
        for (auto r : results) perms.push_back(r);
        return perms;
    }
};
