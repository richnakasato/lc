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
        if (nums.empty()) return 0;
        std::map<int,int> vals;
        std::map<int,int> idxs;
        for (size_t i=0; i<nums.size(); ++i) {
            vals[nums[i]] = i;
            idxs[i] = nums[i];
        }
        int max_count = 0;
        for (int i=0; i<nums.size(); ++i) {
            int val = nums[i];
            int idx = i;

            int count = 1;
            for (std::map<int,int>::const_iterator it=vals.find(nums[i]);
                 it != vals.end();
                 ++it) {
                if (it->first > val && it->second > idx) {
                    ++count;
                    idx = it->second;
                }
            }
            max_count = std::max(max_count, count);

            count = 1;
            for (std::map<int,int>::const_iterator it=idxs.find(i);
                 it != idxs.end();
                 ++it) {
                if (it->second > val) {
                    ++count;
                    val = it->second;
                }
            }
            max_count = std::max(max_count, count);
        }
        return max_count;
    }
};
