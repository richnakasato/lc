/*
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.34%)
 * Total Accepted:    335.6K
 * Total Submissions: 1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 *
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * Example 1:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 *
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (!nums.size()) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        while (lo <= hi) {
            mid = lo + ((hi - lo)/2);
            if (target == nums[lo]) return lo;
            if (target == nums[hi]) return hi;
            if (target == nums[mid]) return mid;
            if (nums[lo] < nums[mid] && nums[mid] < nums[hi]) {
                if (target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else if (nums[lo] > nums[mid] && nums[mid] < nums[hi]) { // left split
                if (target > nums[mid] && target < nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            } else { // nums[lo] < nums[mid] && nums[mid] > nums[hi], right split
                if (target < nums[mid] && target > nums[lo]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return -1;
    }
};
