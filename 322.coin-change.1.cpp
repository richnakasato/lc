class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        int result = helper(arr, amount, 0);
        return result;
    }

private:
    int helper(const std::vector<int>& arr, int amount, int idx)
    {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        int result = 0;
        for (size_t i=idx; i<arr.size(); ++i) {
            int temp = helper(arr, amount - arr[i], i);
            result = temp == -1 ? result : temp + 1;
        }
        return result;
    }
};
