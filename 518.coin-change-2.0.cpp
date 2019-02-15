/*
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (39.72%)
 * Total Accepted:    29.5K
 * Total Submissions: 74.3K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of coin.
 *
 * Note: You can assume that
 *
 *
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input: amount = 10, coins = [10]
 * Output: 1
 *
 *
 *
 *
 */
#include <unordered_map>
#include <vector>

class Solution {
public:
    void helper_bruteforce(const std::vector<int>& coins,
                           int curr_coin,
                           int amount,
                           std::vector<int> curr_coins,
                           std::vector<std::vector<int>>& results)
    {
        if (amount < 0) return;
        if (amount == 0) {
            results.push_back(curr_coins);
            return;
        }
        for (size_t i=curr_coin; i<coins.size(); ++i) {
            std::vector<int> new_coins = curr_coins;
            new_coins.push_back(coins[i]);
            helper_bruteforce(coins, i, amount-coins[i], new_coins, results);
        }
        return;
    }

    int helper_backtrack(const std::vector<int>& coins,
                         int curr_coin,
                         int amount)
    {
        if (amount < 0) return 0;
        if (amount == 0) return 1;
        int nways = 0;
        for (size_t i=curr_coin; i<coins.size(); ++i) {
            nways += helper_backtrack(coins, i, amount-coins[i]);
        }
        return nways;
    }

    int helper_memoization(const std::vector<int>& coins,
                           int amount)
    {
        std::vector<std::vector<int>> memo(coins.size()+1,
                                           std::vector<int>(amount+1));
        memo[0][0] = 1;
        for (size_t curr_coin=0; curr_coin<coins.size(); ++curr_coin) {
            for (int curr_amount=1; curr_amount<=amount; ++curr_amount) {
                int prev_amount = curr_amount - coins[curr_coin];
                if (prev_amount >= 0) {
                    for (size_t prev_coin=0; prev_coin<=curr_coin+1; ++prev_coin) {
                        memo[curr_coin+1][curr_amount] +=
                            memo[prev_coin][prev_amount];
                    }
                }
            }
        }
        int nways = 0;
        for (size_t i=0; i<memo.size(); ++i) {
            nways += memo[i][amount];
        }
        return nways;
    }

    int change(int amount, vector<int>& coins) {
        std::unordered_map<int,int> memo;
        std::vector<std::vector<int>> results;
        memo[0] = 1;
        //helper_bruteforce(coins, 0, amount, {}, results);
        //return results.size();
        //return helper_backtrack(coins, 0, amount);
        return helper_memoization(coins, amount);
    }
};
