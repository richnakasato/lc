/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (52.72%)
 * Total Accepted:    202K
 * Total Submissions: 383.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Example:
 *
 *
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 *
 *
 * Note: Please solve it without division and in O(n).
 *
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 *
 */
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        if (!nums.size()) return result;
        int temp = nums[0];
        for (int i=1; i<result.size(); ++i) {
            result[i] *= temp;
            temp *= nums[i];
        }
        temp = nums[nums.size()-1];
        for (int i=result.size()-2; i>=0; --i) {
            result[i] *= temp;
            temp *= nums[i];
        }
        return result;
    }
};
