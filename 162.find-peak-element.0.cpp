/*
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (40.21%)
 * Total Accepted:    198.8K
 * Total Submissions: 494.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 *
 * You may imagine that nums[-1] = nums[n] = -∞.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2,
 * or index number 5 where the peak element is 6.
 *
 *
 * Note:
 *
 * Your solution should be in logarithmic complexity.
 *
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        // idea: binsearch, choose left or right depending on which side is >
        // cmpx: O(log2 n)
        if (nums.size() == 1) return 0;
        int start = 0;
        int end = nums.size();
        int mid;
        while (start <= end) {
            mid = start + (end-start)/2;
            if (mid == 0) {
                return nums[mid] > nums[mid+1] ? mid : mid+1;
            }
            if (mid == nums.size()-1) {
                return nums[mid] > nums[mid-1] ? mid : mid-1;
            }
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) {
                return mid;
            }
            else if (nums[mid-1] > nums[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return mid;
    }
};
