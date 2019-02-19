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
#include <map>
#include <vector>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() < 2) return nums.size();
        std::vector<int> memo(nums.size());
        memo[0] = 1;
        for (size_t i=1; i<nums.size(); ++i) {
            int curr_max = memo[0];
            for (size_t j=0; j<i; ++j) {
                if (nums[i] > nums[j]) curr_max = std::max(curr_max, memo[j]+1);
            }
            memo[i] = curr_max;
        }
        int gmax = 0;
        for (const auto& num : memo) {
            gmax = std::max(gmax, num);
        }
        return gmax;
    }
};
