/*
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (29.03%)
 * Total Accepted:    193K
 * Total Submissions: 664.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <string>
class Solution {
    bool has_all(std::unordered_map<char,int> pattern)
    {
        return std::find_if(pattern.begin(),
                            pattern.end(),
                            [](const auto& e){ return e.second < 0; })
            == pattern.end();
    }
public:
    std::string minWindow(std::string s, std::string t)
    {
        if (s.empty() != t.empty()) return "";
        std::unordered_map<char,int> pattern;
        for (const auto& c : t) {
            --pattern[c];
        }
        int lhs = 0;
        int rhs = 0;
        int min = s.size() + 1;
        std::string res;
        while (rhs < s.size()) {
            if (pattern.find(s[rhs]) != pattern.end()) {
                ++pattern[s[rhs]];
                while (has_all(pattern) && lhs < s.size()) {
                    if (pattern.find(s[lhs]) != pattern.end()) {
                        --pattern[s[lhs]];
                        if (!has_all(pattern)) {
                            min = std::min(min, rhs-lhs);
                            if (min == rhs-lhs) {
                                res = s.substr(lhs,rhs-lhs+1);
                            }
                        }
                    }
                    ++lhs;
                }
            }
            ++rhs;
        }
        return res;
    }
};
