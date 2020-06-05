#include <random>

class Solution {
public:
    mt19937 gen;
    uniform_int_distribution<int> dist;
    vector<int> buckets;

    Solution(vector<int>& w) {
        random_device rd;
        gen = mt19937(rd());
        auto sum = accumulate(begin(w), end(w), 0);
        dist = std::uniform_int_distribution<int>(1, sum);
        sum = 0;
        buckets = vector<int>(size(w));
        for (auto i=0; i<size(w); ++i) {
            sum += w[i];
            buckets[i] = sum;
        }
    }

    int pickIndex() {
        auto select = dist(gen);
        for (auto i=0; i<size(buckets); ++i) {
            if (select <= buckets[i]) return i;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
