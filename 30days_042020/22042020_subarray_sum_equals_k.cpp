class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto sums = unordered_map<int,int>(); 
        ++sums[0];
        auto count = 0;
        auto sum = 0;
        for (auto rhs=0; rhs < nums.size(); ++rhs) {
            sum += nums[rhs];
            auto target = sum - k;
            if (sums.find(target) != sums.end()) {
               count += sums[target];
            }
            ++sums[sum];
        }
        return count;
    }
};
