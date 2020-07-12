class Solution {
public:
    void helper(const vector<int>& nums,
                int idx,
                vector<int>& curr,
                vector<vector<int>>& results) {
        if (idx == size(nums)) {
            results.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(nums, idx+1, curr, results);
        curr.pop_back();
        helper(nums, idx+1, curr, results);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        auto results = vector<vector<int>>{};
        if (!size(nums)) return results;
        auto idx = 0;
        auto curr = vector<int>{};
        helper(nums, idx, curr, results);
        return results;
    }
};
