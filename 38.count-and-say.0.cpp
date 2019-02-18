/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (38.56%)
 * Total Accepted:    238.7K
 * Total Submissions: 619.1K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 *
 *
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the
 * count-and-say sequence.
 *
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: 1
 * Output: "1"
 *
 *
 * Example 2:
 *
 *
 * Input: 4
 * Output: "1211"
 *
 */
#include <sstream>

class Solution {
public:
    std::string get_say(int count, int number)
    {
        std::string result;
        std::stringstream ss_count;
        ss_count << count;
        result += ss_count.str();
        std::stringstream ss_number;
        ss_number << number;
        result += ss_number.str();
        return result;
    }

    string countAndSay(int n) {
        std::string curr_say = "1";
        for (int i=1; i<=n-1; ++i) {
            int count = 1;
            int number = curr_say[0] - '0';
            std::string next_say;
            for (size_t j=1; j<curr_say.size(); ++j) {
                int digit = curr_say[j] - '0';
                if (digit == number) ++count;
                else {
                    next_say += get_say(count, number);
                    count = 1;
                    number = digit;
                }
            }
            next_say += get_say(count, number);
            curr_say = next_say;
        }
        return curr_say;
    }
};
