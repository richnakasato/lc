/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (57.83%)
 * Total Accepted:    380.1K
 * Total Submissions: 657.2K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,1]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 *
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xord = nums[0];
        for (std::vector<int>::size_type i=1; i<nums.size(); ++i) {
            xord ^= nums[i];
        }
        return xord;
    }
};
