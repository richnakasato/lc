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
        if (!s.empty() && p.empty()) return false;
        int s_idx = 0;
        int p_idx = 0;
        int star = -1;
        int match = -1;
        while (s_idx < s.size()) {
            if (p_idx < p.size() && (s[s_idx] == p[p_idx] || p[p_idx] == '?')) {
                ++s_idx;
                ++p_idx;
            }
            else if (p_idx < p.size() && p[p_idx] == '*')  {
                star = p_idx++;
                match = s_idx;
            }
            else if (star != -1) {
                p_idx = star + 1;
                s_idx = ++match;
            }
            else {
                return false;
            }
        }
        while (p_idx < p.size() && p[p_idx] == '*') {
            ++p_idx;
        }
        return p_idx == p.size();
    }
};
