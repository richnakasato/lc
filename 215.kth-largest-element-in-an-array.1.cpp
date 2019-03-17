/*
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (44.28%)
 * Total Accepted:    288.1K
 * Total Submissions: 650.7K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */
class Solution {
    size_t pivot(std::vector<int>& nums, size_t start, size_t end) {
        int pivot = nums[end-1];
        size_t p_idx = start;
        for (size_t i=start; i<end-1; ++i) {
            if (nums[i] < pivot) {
                std::swap(nums[i], nums[p_idx]);
                ++p_idx;
            }
        }
        std::swap(nums[end-1], nums[p_idx]);
        return p_idx;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        size_t start = 0;
        size_t end = nums.size();
        size_t kth = 0;
        size_t p_idx = 0;
        while (start < end) {
            p_idx = pivot(nums, start, end);
            kth = nums.size() - p_idx;
            if (k == kth) {
                break;
            }
            else if (k < kth) {
                start = p_idx + 1;
            }
            else {
                end = p_idx;
            }
        }
        return nums[p_idx];
    }
};
