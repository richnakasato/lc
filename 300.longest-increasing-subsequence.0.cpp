/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.60%)
 * Total Accepted:    172.2K
 * Total Submissions: 434.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 * Example:
 *
 *
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4.
 *
 * Note:
 *
 *
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 */
#include <algorithm>
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int g_max_count = 1;
        for (size_t i=0; i<nums.size(); ++i) {
            int l_max_count = 1;
            int curr_count = 1;
            int last = nums[i];
            for (size_t j=i+1; j<nums.size(); ++j) {
                if (nums[j] >= last) { ++curr_count; }
                else {
                    l_max_count = std::max(l_max_count, curr_count);
                    curr_count = 1;
                }
                last = nums[j];
            }
            l_max_count = std::max(l_max_count, curr_count);
            g_max_count = std::max(g_max_count, l_max_count);
        }
        return g_max_count;
    }
};
