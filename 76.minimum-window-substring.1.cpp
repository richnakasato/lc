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
class Solution {
    bool all_found(const std::unordered_map<char,int>& counts) {
        return std::find_if(counts.begin(),
                            counts.end(),
                            [](const std::pair<char,int>& e){ e.second == 0; })
            == counts.end();
    }
public:
    string minWindow(string s, string t) {
        if (s.empty() != t.empty())
            return "";
        std::unordered_map<char,int> counts;
        for (const auto& c : t)
            counts[c] = 0;
        int lhs = 0;
        int rhs = 0;
        int min = std::numeric_limits<int>::max();
        while (rhs < s.size()) {
            while (!all_found(counts)) {
            }
            while (!all_foundcounts.find(s[rhs]) == counts.end())
                ++rhs;
            rhs = lhs;
            while (rhs < s.size() && !all_found(counts)) {
                if (counts.find(s[rhs]) != counts.end())
                    ++counts[s[rhs]];
                ++rhs;
            }
            if (all_found(counts)) {
                min = std::min(min, rhs-lhs);
            }
        }
    }
};
