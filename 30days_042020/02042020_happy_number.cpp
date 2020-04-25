class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> memo;
        while (n != 1 && memo.find(n) == memo.end()) {
            memo.insert(n);
            int sum = 0;
            while (n) {
                int val = n % 10;
                sum += (val * val);
                n = n / 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
