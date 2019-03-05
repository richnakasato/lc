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
#include <unordered_set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        int lhs = 0;
        int rhs = 0;
        std::unordered_set<char> seen;
        int gcount = 0;
        int lcount = 0;
        while (rhs < s.size()) {
            if (seen.find(s[rhs]) != seen.end()) {
                gcount = std::max(gcount, lcount);
                while (s[lhs] != s[rhs]) {
                    seen.erase(s[lhs++]);
                    --lcount;
                }
                seen.erase(s[lhs++]);
                --lcount;
            }
            seen.insert(s[rhs++]);
            ++lcount;
        }
        return std::max(gcount, lcount);
    }
};
