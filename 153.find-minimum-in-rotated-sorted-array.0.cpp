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
    int helper(const vector<int>& nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        int mid = start + (end-start)/2;
        if (nums[mid] > nums[end]) {
            return helper(nums, mid+1, end);
        }
        else {
            return helper(nums, start, mid);
        }
    }
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;
        return helper(nums, 0, nums.size()-1);
    }
};
