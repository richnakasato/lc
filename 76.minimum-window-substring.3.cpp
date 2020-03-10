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
class Solution {
public:
    bool hasAll(const std::unordered_map<char, int>& counts) {
        for (auto count : counts) {
            if (count.second > 0) return false;
        }
        return true;
    }

    std::string minWindow(std::string s, std::string t) {
        if (!s.size()
            || !t.size()
            || t.size() > s.size()) return "";

        std::unordered_map<char, int> t_counts;
        for (int i=0; i<t.size(); ++i) {
            ++t_counts[t[i]];
        }

        int min = std::numeric_limits<int>::max();
        std::string result = "";
        int lhs = 0;
        int rhs = 0;
        while (rhs < s.size()) {
            if (t_counts.find(s[rhs]) != t_counts.end()) {
                --t_counts[s[rhs]];
                if (t_counts[s[rhs]] < 1  && hasAll(t_counts)) {
                    while (lhs < s.size() && hasAll(t_counts)) {
                        if (t_counts.find(s[lhs]) != t_counts.end()) {
                            ++t_counts[s[lhs]];
                        }
                        ++lhs;
                    }
                    min = std::min(min, rhs - lhs);
                    if (min == rhs - lhs) {
                        result = s.substr(lhs-1, rhs-lhs+2);
                    }
                }
            }
            ++rhs;
        }
        return result;
    }
};
