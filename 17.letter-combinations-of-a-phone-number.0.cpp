/*
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (39.18%)
 * Total Accepted:    312.2K
 * Total Submissions: 796.8K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 * Example:
 *
 *
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 *
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    void helper(const std::unordered_map<char,std::string>& keypad,
                std::string digits,
                std::string combo,
                std::vector<std::string>& results)
    {
        if (digits.empty()) {
            results.push_back(combo);
            return;
        }
        char digit = digits[0];
        digits = digits.substr(1,digits.size());
        for (size_t letter=0; letter<keypad.at(digit).size(); ++letter) {
            std::string new_combo = combo + keypad.at(digit)[letter];
            helper(keypad, digits, new_combo, results);
        }
        return;
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};
        std::unordered_map<char,std::string> keypad {{'1',""},
                                                     {'2',"abc"},
                                                     {'3',"def"},
                                                     {'4',"ghi"},
                                                     {'5',"jkl"},
                                                     {'6',"mno"},
                                                     {'7',"pqrs"},
                                                     {'8',"tuv"},
                                                     {'9',"wxyz"},
                                                     {'0',""}};
        std::vector<std::string> results;
        helper(keypad, digits, "", results);
        return results;
    }
};
