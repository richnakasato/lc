/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (49.81%)
 * Total Accepted:    272.9K
 * Total Submissions: 547.9K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 *
 */
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char,int> counts;
        for (const auto& c : s) {
            ++counts[c];
        }
        for (const auto& c : t) {
            --counts[c];
        }
        for (const auto& e : counts) {
            if (e.second != 0) {
                return false;
            }
        }
        return true;
    }
};
