/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (50.22%)
 * Total Accepted:    196.5K
 * Total Submissions: 391.2K
 * Testcase Example:  '"A"'
 *
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 *
 * For example:
 *
 *
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28
 * ⁠   ...
 *
 *
 * Example 1:
 *
 *
 * Input: "A"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: "AB"
 * Output: 28
 *
 *
 * Example 3:
 *
 *
 * Input: "ZY"
 * Output: 701
 *
 */
class Solution {
public:
    int titleToNumber(string s) {
        int pow = 0;
        int result = 0;
        int alpha_sz = 26;
        for (std::string::const_reverse_iterator it = s.crbegin();
             it != s.crend();
             ++it) {
            int letter_val = (*it - 'A') + 1;
            result += letter_val * std::pow(alpha_sz, pow++);
        }
        return result;
    }
};
