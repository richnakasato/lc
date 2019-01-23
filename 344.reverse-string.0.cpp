/*
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (62.01%)
 * Total Accepted:    330.9K
 * Total Submissions: 533.6K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and returns the string
 * reversed.
 *
 * Example 1:
 *
 *
 *
 * Input: "hello"
 * Output: "olleh"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: "amanaP :lanac a ,nalp a ,nam A"
 *
 *
 *
 *
 */
class Solution {
public:
    void reverseString(std::vector<char>& s) {
        typedef std::vector<char>::size_type vec_sz;
        vec_sz left = 0;
        vec_sz right = s.size()-1;
        while (left < right) {
            ++left;
            --right;
        }
    }
};
