class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (size(nums)==1) return nums[0];
        auto memo = unordered_map<int,int>{};
        for (auto num : nums) {
            ++memo[num];
        }
        for (auto e : memo) {
            if (e.second == 1) return e.first;
        }
        return -1;
    }
};
