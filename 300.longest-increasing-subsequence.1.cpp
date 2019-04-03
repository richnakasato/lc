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
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 2) return nums.size();
        std::vector<int> lis(nums.size(),0);
        lis[0] = 1;
        for (int rhs=1; rhs<nums.size(); ++rhs) {
            for (int lhs=0; lhs<rhs; ++lhs) {
                if (nums[lhs] < nums[rhs]) {
                    lis[rhs] = max(lis[rhs], lis[lhs]);
                }
            }
            ++lis[rhs];
        }
        return *std::max_element(lis.begin(), lis.end());
    }
};
