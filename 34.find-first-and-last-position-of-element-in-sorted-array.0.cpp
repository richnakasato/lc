/*
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (32.42%)
 * Total Accepted:    243.3K
 * Total Submissions: 750.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */
class Solution {
    int binsearch_helper(const std::vector<int>& nums, int target, bool hi)
    {
        int lhs = 0;
        int rhs = nums.size() - 1;
        int last = -1;
        while (lhs <= rhs) {
            int mid = lhs + ((rhs - lhs)/2);
            if (nums[mid] == target) {
                if (hi) {
                    lhs = mid+1;
                }
                else {
                    rhs = mid-1;
                }
                last = mid;
            }
            else if (nums[mid] > target) {
                rhs = mid-1;
            }
            else {
                lhs = mid+1;
            }
        }
        return last;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        std::vector<int> pair = {-1,-1};
        if (nums.empty()) return pair;
        if (target < nums.front()) return pair;
        if (target > nums.back()) return pair;
        pair[0] = binsearch_helper(nums, target, false);
        pair[1] = binsearch_helper(nums, target, true);
        return pair;
    }
};
