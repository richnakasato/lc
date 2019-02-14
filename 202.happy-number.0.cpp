/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (43.44%)
 * Total Accepted:    197.5K
 * Total Submissions: 454.6K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 
 *
 *
 * Input: 19
 * Output: true
 * Explanation:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 */
#include <cmath>
#include <unordered_set>
class Solution {
public:
    int sum_squares(int n) {
        int sum = 0;
        while (n) {
            sum += std::pow(n%10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> seen;
        while (seen.find(n) == seen.end()) {
            seen.insert(n);
            n = sum_squares(n);
            if (n == 1) return true;
        }
        return false;
    }
};
