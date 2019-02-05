/*
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (48.75%)
 * Total Accepted:    61.1K
 * Total Submissions: 125.2K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */
#include <random>
#include <vector>

class Solution {
public:
    Solution(vector<int> nums) : orig{nums}, shuf{nums} {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        shuf = orig;
        return shuf;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (std::vector<int>::size_type i=shuf.size(); i-->0;) {
            int rand_idx = rand_int(0, i);
            std::swap(shuf[rand_idx], shuf[i]);
        }
        return shuf;
    }
private:
    int rand_int(int start, int end) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(start, end);
        return dis(gen);
    }

    std::vector<int> orig;
    std::vector<int> shuf;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
