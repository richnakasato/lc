/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (29.31%)
 * Total Accepted:    292.9K
 * Total Submissions: 999.4K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.length()) return true;
        std::transform(s.begin(), s.end(), s.begin(),
                [](char& c){ return std::tolower(c); });
        int lhs = 0;
        int rhs = s.length() - 1;
        while (lhs < rhs) {
            if (!std::isalnum(s[lhs])) {
                ++lhs;
            } else if (!std::isalnum(s[rhs])) {
                --rhs;
            } else {
                if (s[lhs] != s[rhs]) {
                    return false;
                }
                ++lhs;
                --rhs;
            }
        }
        return true;
    }
};
