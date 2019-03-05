/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (40.19%)
 * Total Accepted:    221.9K
 * Total Submissions: 552.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 *
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 *
 * Example:
 *
 *
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 *
 */
class Solution {
public:
    int trap(vector<int>& height)
    {
        if (height.size() < 2) return 0;

        std::vector<int> max_left(height.size());
        int curr_max = 0;
        for (size_t i=0; i<max_left.size(); ++i) {
            curr_max = std::max(curr_max, height[i]);
            max_left[i] = curr_max;
        }
        std::vector<int> max_right(height.size());
        curr_max = 0;
        for (size_t i=max_right.size(); i-->0;) {
            curr_max = std::max(curr_max, height[i]);
            max_right[i] = curr_max;
        }

        int total = 0;
        for (size_t i=0; i<height.size(); ++i) {
            total += std::min(max_left[i], max_right[i]) - height[i];
        }
        return total;
    }
};
