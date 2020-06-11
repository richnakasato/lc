// Plan: Binary search.  Perform binary search for target, tracking idx of where it should be as you move along.
// Time: n log n
// Space: log n

class Solution {
public:
    int searchHelper(vector<int>& nums, int target, int lo, int hi) {
        auto mid = lo + ((hi - lo) / 2);
        if (lo > hi) {
            return mid;
        }
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) {
            return searchHelper(nums, target, lo, mid-1);
        } else {
            return searchHelper(nums, target, mid+1, hi);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size()-1);
    }
};
