/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (27.93%)
 * Total Accepted:    140.1K
 * Total Submissions: 501.6K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 * Example 1:
 *
 *
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 *
 * Example 2:
 *
 *
 * Input: coins = [2], amount = 3
 * Output: -1
 *
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!coins.size()) return -1;
        if (!amount) return 0;
        std::sort(coins.begin(), coins.end());
        std::vector<int> num_coins(amount+1, amount+1);
        num_coins[0] = 0;
        for (int coin=0; coin<coins.size(); ++coin) {
            for (int curr_amount=1; curr_amount<num_coins.size(); ++curr_amount) {
                if (coins[coin] <= curr_amount) {
                    int prev_amount = curr_amount - coins[coin];
                    num_coins[curr_amount] = std::min(num_coins[curr_amount],
                                                      num_coins[prev_amount] + 1);
                }
            }
        }
        return num_coins[amount] <= amount ? num_coins[amount] : -1;
    }
};
