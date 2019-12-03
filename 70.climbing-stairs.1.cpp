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
class Solution {
public:
    int climbStairs(int n) {
        if (!n) return 1;
        std::vector<int> n_ways(n+1, 0);
        n_ways[0] = 1;
        n_ways[1] = 1;
        for (int i=2; i<n+1; ++i) {
            n_ways[i] = n_ways[i-1] + n_ways[i-2];
        }
        return n_ways[n];
    }
};
