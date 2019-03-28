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
    int partition(vector<int>& nums, int start, int end)
    {
        int tail = end-1;
        int pivot = nums[tail];
        int p_idx = start;
        for (int i=start; i<tail; ++i) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[p_idx]);
                ++p_idx;
            }
        }
        swap(nums[tail], nums[p_idx]);
        return p_idx;
    }
    public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int start = 0;
        int end = nums.size();
        int p_idx;
        int kth;
        while (start < end) {
            p_idx = partition(nums, start, end);
            kth = nums.size() - p_idx;
            if (kth == k) return nums[p_idx];
            else if (kth > k) {
                start = p_idx + 1;
            }
            else {
                end = p_idx;
            }
        }
        return -1;
    }
};
