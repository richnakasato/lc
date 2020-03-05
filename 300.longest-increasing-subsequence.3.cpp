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
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> max(nums.size(), 1);
        for (int rhs=0; rhs<nums.size(); ++rhs) {
            int lhs = 0;
            while (lhs < rhs) {
                if (nums[lhs] < nums[rhs]) {
                    max[rhs] = std::max(max[rhs], max[lhs] + 1);
                }
                ++lhs;
            }
        }
        int max_len = 0;
        for (int i=0; i<max.size(); ++i) {
           max_len = std::max(max_len, max[i]);
        }
        return max_len;
    }
};
