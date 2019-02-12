/*
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (45.80%)
 * Total Accepted:    157.4K
 * Total Submissions: 343.5K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
#include <unordered_map>

// idea: figure out which input is shorter and put it in a set
//       iterate through longer on and add all found to output vec
// cplx: T.O(n+m), S.O(m)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return helper(nums1, nums2);
        }
        else {
            return helper(nums2, nums1);
        }
    }

    std::vector<int> helper(std::vector<int>& long_, std::vector<int>& short_)
    {
        std::unordered_map<int,int> counts;
        for (const auto& num : short_)
            ++counts[num];
        std::vector<int> results;
        for (const auto& num : long_) {
            if (counts.find(num) != counts.end() && counts[num] > 0) {
                results.push_back(num);
                --counts[num];
            }
        }
        return results;
    }
};
