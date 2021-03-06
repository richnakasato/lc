/*
 * [44] Wildcard Matching
 *
 * https://leetcode.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (21.95%)
 * Total Accepted:    151.7K
 * Total Submissions: 690.9K
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement wildcard pattern
 * matching with support for '?' and '*'.
 *
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 * Note:
 *
 *
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like ? or *.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "aa"
 * p = "*"
 * Output: true
 * Explanation: '*' matches any sequence.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "cb"
 * p = "?a"
 * Output: false
 * Explanation: '?' matches 'c', but the second letter is 'a', which does not
 * match 'b'.
 *
 *
 * Example 4:
 *
 *
 * Input:
 * s = "adceb"
 * p = "*a*b"
 * Output: true
 * Explanation: The first '*' matches the empty sequence, while the second '*'
 * matches the substring "dce".
 *
 *
 * Example 5:
 *
 *
 * Input:
 * s = "acdcb"
 * p = "a*c?b"
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        auto lhs = 0;
        auto rhs = 0;
        auto last = 0;
        auto star = -1;
        while (lhs < s.size()) {
            if (rhs < p.size()
                && s[lhs] == p[rhs]
                || p[rhs] == '?') {
                ++lhs;
                ++rhs;
            }
            else if (rhs < p.size()
                     && p[rhs] == '*') {
                last = lhs;
                star = rhs;
                ++rhs;
            }
            else if (rhs < p.size()
                     && star != -1) {
                lhs = last + 1;
                rhs = star;
                ++rhs;
            }
            else {
                return false;
            }
        }
        while (rhs < p.size() && p[rhs] == '*') {
            ++rhs;
        }
        return lhs == s.size() && rhs == p.size();
    }
};
