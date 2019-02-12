/*
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (46.72%)
 * Total Accepted:    224.7K
 * Total Submissions: 480.9K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 *
 * Example 1:
 *
 *
 * Input: [3,0,1]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 *
 *
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xored = 0;
        for (int i=1; i<=nums.size(); ++i) {
            xored ^= i;
        }
        for (int i=0; i<nums.size(); ++i) {
            xored ^= nums[i];
        }
        return xored;
    }
};