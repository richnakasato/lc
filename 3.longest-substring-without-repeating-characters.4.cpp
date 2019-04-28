/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (25.50%)
 * Total Accepted:    665.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 *
 *
 *
 *
 *
 */
#include <algorithm>
#include <string>
#include <unordered_map>
/* Sliding window (aka 2 ptrs problem)
 * - add at rhs, check if in set, add if not, ++rhs
 * - if in set, set max to rhs - lhs, move ++lhs
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        std::unordered_map<char,int> counts;
        int lhs = 0;
        int rhs = 0;
        int max = 0;
        while (rhs < s.size()) {
            ++counts[s[rhs]];
            if (counts[s[rhs]] > 1) {
                while(counts[s[lhs]] < 2) {
                    --counts[s[lhs]];
                    ++lhs;
                }
                --counts[s[lhs]];
                ++lhs;
            }
            max = std::max(max, rhs-lhs+1);
            ++rhs;
        }
        return max;
    }
};
