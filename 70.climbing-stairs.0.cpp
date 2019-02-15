/*
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (42.52%)
 * Total Accepted:    320.2K
 * Total Submissions: 753K
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 *
 * Note: Given n will be a positive integer.
 *
 * Example 1:
 *
 *
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 *
 *
 * Example 2:
 *
 *
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 *
 *
 */
#include <unordered_map>
#include <vector>

class Solution {
public:
    int helper(std::vector<int>& allowed_steps,
               int n,
               std::unordered_map<int,int>& memo) {
        if (n < 0) return 0;
        if (n == 1) return 1;
        if (memo[n] > 0) return memo[n];

        int nways = 0;
        for (const auto& step : allowed_steps) {
            nways += helper(allowed_steps, n-step, memo);
        }
        memo[n] = nways;
        return memo[n];
    }

    int climbStairs(int n)
    {
        std::vector<int> allowed_steps {1,2};
        std::unordered_map<int,int> memo;
        memo[0] = 1;
        return helper(allowed_steps, n, memo);
    }
};
