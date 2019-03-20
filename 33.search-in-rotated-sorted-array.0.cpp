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
        if (nums[start] == target) return start;
        if (nums[mid] == target) return mid;
        if (nums[end] == target) return end;

        if (nums[mid] > nums[end]) {
            if (nums[mid] < target && nums[end] < target) {
                return helper(nums, target, mid+1, end);
            }
            else if (nums[mid] > target && nums[end] > target) {
                return helper(nums, target, mid+1, end);
            }
            else {
                return helper(nums, target, start, mid);
            }
        }
        else {
            if (target < nums[mid] && target < nums[end]) {
                return helper(nums, target, start, mid);
            }
            else if (target > nums[mid] && target > nums[end]) {
                return helper(nums, target, start, mid);
            }
            else {
                return helper(nums, target, mid+1, end);
            }
        }
    }
public:
    int search(const vector<int>& nums, int target)
    {
        int result = -1;
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while (start <= end) {
            mid = start + (end-start)/2;
            if (nums[start] == target) return start;
            if (nums[mid] == target) return mid;
            if (nums[end] == target) return end;
            if (nums[mid] > nums[end]) {
                if (target < nums[mid] && target < nums[end]) {
                    start = mid+1;
                }
                else if (target > nums[mid] && target > nums[end]) {
                    start = mid+1;
                }
                else {
                    end = mid-1;
                }
            }
            else {
                if (target < nums[mid] && target < nums[end]) {
                    end = mid-1;
                }
                else if (target > nums[mid] && target > nums[end]) {
                    end = mid-1;
                }
                else {
                    start = mid+1;
                }
            }
        }
        return result;
    }
};
