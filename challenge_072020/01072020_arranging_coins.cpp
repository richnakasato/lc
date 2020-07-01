// Plan: Track two variables, step size and count, iteratively increment step size and subtract from n and increment count as long as n - step size is non-negative.
// Time: n
// Space: 1

class Solution {
public:
    int arrangeCoins(int n) {
        if (n < 2) return n;
        auto step_size = 1;
        auto count = 0;
        while (n - step_size >= 0) {
            n-=step_size++;
            ++count;
        }
        return count;
    }
};
