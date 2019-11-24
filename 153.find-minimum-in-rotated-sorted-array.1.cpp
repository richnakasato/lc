/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (42.01%)
 * Total Accepted:    241.3K
 * Total Submissions: 574.3K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,4,5,1,2]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 *
 *
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        int min_seen = std::numeric_limits<int>::max();
        while (lo <= hi) {
            mid = lo + (hi - lo)/2;
            min_seen = std::min(min_seen, nums[mid]);
            if (nums[lo] <= nums[mid] && nums[mid] >= nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return min_seen;
    }
};
