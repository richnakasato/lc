/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (49.68%)
 * Total Accepted:    275.6K
 * Total Submissions: 554.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 *
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 *
 * Example 1:
 *
 *
 * Input: [1,2,3,1]
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,4]
 * Output: false
 *
 * Example 3:
 *
 *
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 */
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (std::vector<int>::size_type i=1; i<nums.size(); ++i) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
};
