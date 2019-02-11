/*
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (46.99%)
 * Total Accepted:    147.8K
 * Total Submissions: 314.5K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 *
 * Example 1:
 *
 *
 * Input: [1,3,4,2,2]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [3,1,3,4,2]
 * Output: 3
 *
 * Note:
 *
 *
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 *
 *
 */
#include <algorithm>

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // fully realize this breaks 1st rule (did not come up with cycle alg)
        std::sort(nums.begin(), nums.end());
        for (size_t i=1; i<nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                return nums[i];
        }
        return -1;
    }
};
