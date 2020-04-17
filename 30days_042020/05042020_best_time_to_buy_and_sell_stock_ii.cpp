class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        if (prices.size() < 2) return maxP;
        for (int rhs=1; rhs<prices.size(); ++rhs) {
            int lhs = rhs - 1;
            maxP += prices[rhs] > prices[lhs] ? prices[rhs] - prices[lhs] : 0;
        }
        return maxP;
    }
};
