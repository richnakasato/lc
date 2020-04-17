class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2) return;
        int tgt = 0;
        int dst = 0;
        for (int src=0; src<nums.size(); ++src) {
            if (nums[src] != tgt) {
                std::swap(nums[dst++], nums[src]);
            }
        }
        return;
    }
};
