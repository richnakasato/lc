/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (39.27%)
 * Total Accepted:    1.2M
 * Total Submissions: 3.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */
#include <unordered_map>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::vector<int> result;
            if (!nums.size()) return result;
            std::unordered_map<int, int> seen;
            for (int i=0; i<nums.size(); ++i) {
                int other_target = target - nums[i];
                if (seen.find(other_target) == seen.end()) {
                    seen.insert({nums[i], i});
                } else {
                    return {i, seen[other_target]};
                }
            }
            return result;
        }
};
