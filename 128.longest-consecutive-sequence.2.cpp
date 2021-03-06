/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (40.07%)
 * Total Accepted:    176.7K
 * Total Submissions: 441K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
#include <algorithm>
#include <limits>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        std::unordered_set<int> seen;
        for (const auto& num : nums) {
            seen.insert(num);
        }
        int max = std::numeric_limits<int>::min();
        for (const auto& num : nums) {
            if (seen.find(num+1) == seen.end()) {
                int count = 0;
                int seq = num;
                while (seen.find(seq) != seen.end()) {
                    ++count;
                    --seq;
                }
                max = std::max(max, count);
            }
        }
        return max;
    }
};
