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
    int helper(const vector<int>& nums, int target, int start, int end)
    {
        if (start == end) {
            if (nums[start]==target) return start;
            else return -1;
        }
        int mid = start + (end-start)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > nums[end]) {
            if (nums[mid] < target ||
                nums[end] >= target) {
                return helper(nums, target, mid+1, end);
            } // go right
            else {
                return helper(nums, target, start, mid);
            } // go left
        }
        else {
            if (target < nums[mid]) {
                return helper(nums, target, start, mid);
            } // go left
            else {
                return helper(nums, target, mid+1, end);
            } // go right
        }
    }
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;
        if (nums.size()==1) {
            if (nums[0]==target) return 0;
            else return -1;
        }
        return helper(nums, target, 0, nums.size()-1);
    }
};
