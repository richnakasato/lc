/*
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (40.07%)
 * Total Accepted:    176.7K
 * Total Submissions: 441K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 *
 * Your algorithm should run in O(n) complexity.
 *
 * Example:
 *
 *
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen;
        for (const auto& num : nums) {
            seen.insert(num);
        }
        int gcount = 0;
        for (size_t i=0; i<nums.size(); ++i) {
            int cur_seq = nums[i];
            if (seen.find(cur_seq+1) == seen.end()) {
                int lcount = 0;
                while (seen.find(cur_seq) != seen.end()) {
                    ++lcount;
                    --cur_seq;
                }
                gcount = std::max(gcount, lcount);
            }
        }
        return gcount;
    }
};
