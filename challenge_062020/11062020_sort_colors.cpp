class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (size(nums) < 2) return;
        if (size(nums) == 2) {
            if (nums[0] > nums[1]) swap(nums[0], nums[1]);
            return;
        }
        int lo = 0;
        int hi = size(nums)-1;
        int curr = 0;
        while (curr <= hi) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[lo++]);
            } else if (nums[curr] == 1) {
                ++curr;
            } else {
                swap(nums[curr], nums[hi--]);
            }
        }
        return;
    }
};
