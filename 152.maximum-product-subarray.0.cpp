/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (27.95%)
 * Total Accepted:    174.7K
 * Total Submissions: 625.2K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;
        int max_prod = std::numeric_limits<int>::min();
        int cur_prod = 1;
        for (int i=0; i<nums.size(); ++i) {
            cur_prod *= nums[i];
            max_prod = std::max(max_prod, cur_prod);
            if (!cur_prod) cur_prod = 1;
        }
        cur_prod = 1;
        for (int i=nums.size(); i-->0;) {
            cur_prod *= nums[i];
            max_prod = std::max(max_prod, cur_prod);
            if (!cur_prod) cur_prod = 1;
        }
        return max_prod;
    }
};
