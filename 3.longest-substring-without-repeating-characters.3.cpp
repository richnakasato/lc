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
#include <tuple>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        std::unordered_map<char,int> counts;
        size_t lhs = 0;
        size_t rhs = 0;
        size_t max_substr = 0;
        std::tuple<size_t,size_t> max_idxs;
        while (rhs < s.size()) {
            ++counts[s[rhs]];
            if (counts[s[rhs]] > 1) {
                while (counts[s[lhs]] < 2) {
                    --counts[s[lhs++]];
                }
                --counts[s[lhs++]];
            }
            max_substr = std::max(max_substr, rhs-lhs+1);
            if (max_substr == rhs-lhs+1) {
                max_idxs = std::make_tuple(lhs, rhs);
            }
            ++rhs;
        }
        //std::cout << std::get<0>(max_idxs) << ", " << std::get<1>(max_idxs);
        return max_substr;
    }
};
