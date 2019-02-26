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
#include <set>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        std::unordered_set<int> seen;
        for (const auto& num : nums) {
            seen.insert(num);
        }
        int gmax = 1;
        for (size_t i=0; i<nums.size(); ++i) {
            int num = nums[i];
            int lmax = 1;
            while (seen.find(num+1) != seen.end()) {
                lmax += 1;
                ++num;
            }
            gmax = std::max(gmax, lmax);
        }
        return gmax;
    }
    /*
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        std::set<int> seen;
        for (const auto& num : nums) {
            seen.insert(num);
        }
        std::set<int>::iterator it = seen.begin();
        int last = *it++;
        int lmax = 1;
        int gmax = 1;
        for (;it!=seen.end(); ++it) {
            if (*it == last + 1) {
                ++lmax;
                ++last;
            }
            else {
                gmax = std::max(gmax, lmax);
                lmax = 1;
                last = *it;
            }
        }
        gmax = std::max(gmax, lmax);
        return gmax;
    }
    */
};
