class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (size(digits) == 1 and digits[0] == 0) return vector<int>{1};
        auto result = vector<int>{};
        int carry = 1;
        for (auto i=size(digits); i-->0;) {
            int sum = digits[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) result.push_back(1);
        int lhs = 0;
        int rhs = size(result) - 1;
        while (lhs < rhs) {
            swap(result[lhs++], result[rhs--]);
        }
        return result;
    }
};
