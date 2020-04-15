class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return std::numeric_limits<int>::min();
        int gMax = nums[0];
        int lMax = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            lMax = std::max(nums[i], lMax + nums[i]);
            gMax = std::max(lMax, gMax);
        }
        return gMax;
    }
};
