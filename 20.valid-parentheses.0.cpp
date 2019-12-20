/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.16%)
 * Total Accepted:    456.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 * Note that an empty string is also considered valid.
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: "{[]}"
 * Output: true
 *
 *
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        if (s.size() == 1) return false;
        std::unordered_map<char,char> brackets = {{'(',')'},
                                                  {'[',']'},
                                                  {'{','}'}};
        std::vector<char> stack;
        for (auto c : s) {
            auto search = brackets.find(c);
            if (search != brackets.end()) {
                stack.push_back(search->second);
            } else {
                if (stack.empty()) return false;
                if (c != stack.back()) return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
