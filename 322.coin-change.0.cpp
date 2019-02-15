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
        if (amount == 0) return 0;
        if (coins.empty()) return -1;
        std::sort(coins.begin(), coins.end());
        if (amount < coins[0]) return -1;

        std::vector<std::vector<int>> memo(coins.size()+1,
                                           std::vector<int>(amount+1,-1));
        memo[0][0] = 0;
        for (size_t curr_coin=0; curr_coin<coins.size(); ++curr_coin) {
            for (int curr_amount=1; curr_amount<=amount; ++curr_amount) {
                int prev_amount = curr_amount - coins[curr_coin];
                if (prev_amount >= 0) {
                    int min_count = std::numeric_limits<int>::max();
                    for (size_t prev_coin=0; prev_coin<=curr_coin+1; ++prev_coin) {
                        int prev_count = memo[prev_coin][prev_amount];
                        if (prev_count != -1) {
                            min_count = std::min(min_count, prev_count);
                        }
                    }
                    int val = min_count != std::numeric_limits<int>::max() ?
                              1 + min_count : -1;
                    memo[curr_coin+1][curr_amount] = val;
                }
            }
        }
        int min_ways = std::numeric_limits<int>::max();
        for (size_t i=0; i<memo.size(); ++i) {
            if (memo[i][amount] != -1)
                min_ways = std::min(min_ways, memo[i][amount]);
        }
        return min_ways != std::numeric_limits<int>::max() ? min_ways : -1;
    }
};
