// Plan: DP, 2d vector, calculate amounts of coins for each amount subtracing value of coin
// Time: amount * coins.size()
// Space: amount

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        auto n_ways = vector<int>(amount+1);
        n_ways[0] = 1;
        for (auto ci=0; ci<size(coins); ++ci) {
            auto val = coins[ci];
            for (auto ai=val; ai<size(n_ways); ++ai) {
                n_ways[ai] += n_ways[ai-val];
            }
        }
        return n_ways[amount];
    }
};
