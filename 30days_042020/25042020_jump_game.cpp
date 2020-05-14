class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        auto max_seen = 0;
        for (auto i=0; i<nums.size() - 1; ++i) {
            if (max_seen < i) break;
            auto sum = i + nums[i];
            if (sum >= nums.size() - 1) return true;
            max_seen = max(max_seen, sum);
        }
        return false;
    }
};
