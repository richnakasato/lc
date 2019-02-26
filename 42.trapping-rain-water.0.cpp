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

        std::vector<int> max_ahead(height.size());
        int max_seen = 0;
        for (size_t i=height.size(); i-->0;) {
            max_ahead[i] = max_seen;
            max_seen = std::max(max_seen, height[i]);
        }

        int captured = 0;
        int blocked = 0;
        int left = 0;
        int right = 1;
        while (left < height.size()) {
            if (height[left] == 0 || height[left] > max_ahead[left]) {
                blocked = 0;
                ++left;
                right = left + 1;
            }
            else {
                while (right < height.size() && height[right] < height[left]) {
                    blocked += height[right];
                    ++right;
                }
                if (right < height.size() && height[right] >= height[left]) {
                    captured += volume(height, left, right) - blocked;
                    blocked = 0;
                    left = right;
                    right = left + 1;
                }
                else {
                    blocked = 0;
                    ++left;
                    right = left + 1;
                }
            }
        }
        return captured;
    }

private:
    int volume(const std::vector<int>& height, int left, int right)
    {
        int min_h = std::min(height[left], height[right]);
        return min_h * (right-left-1);
    }
};
