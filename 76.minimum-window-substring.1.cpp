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
    bool all_found(const std::unordered_map<char,int>& remaining) {
        //return std::find_if(remaining.begin(),
        //                    remaining.end(),
        //                    [](const std::pair<char,int>& e){ e.second > 0; })
        //    == remaining.end();
        for (const auto& e : remaining) {
            if (e.second > 0) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        if (s.empty() != t.empty())
            return "";
        std::unordered_map<char,int> remaining;
        for (const auto& c : t) {
            ++remaining[c];
        }
        int lhs = 0;
        int rhs = 0;
        int min = std::numeric_limits<int>::max();
        std::string res;
        while (lhs < s.size()) {
            if (remaining.find(s[lhs]) != remaining.end()) {
                --remaining[s[lhs]];
            }
            if (all_found(remaining)) {
                while (rhs < s.size() && all_found(remaining)) {
                    if (remaining.find(s[rhs]) != remaining.end()) {
                        ++remaining[s[rhs]];
                    }
                    if (!all_found(remaining)) {
                        min = std::min(min, lhs-rhs);
                        if (min == lhs-rhs) {
                            res = s.substr(rhs, lhs-rhs+1);
                        }
                    }
                    ++rhs;
                }
            }
            ++lhs;
        }
        return res;
    }
};
