/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (40.63%)
 * Total Accepted:    278.7K
 * Total Submissions: 686.1K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 *
 *
 *
 *
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49.
 *
 *
 *
 * Example:
 *
 *
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 *
 */
class Solution {
public:
    int calcVol(const std::vector<int>& vec, const int lhs, const int rhs) {
        return (rhs - lhs) * std::min(vec[lhs], vec[rhs]);
    }
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int lhs = 0;
        int rhs = height.size() - 1;
        int curVol = 0;
        int maxVol = 0;
        while (lhs < rhs) {
            curVol = calcVol(height, lhs, rhs);
            maxVol = std::max(curVol, maxVol);
            if (height[lhs] == height[rhs]) {
                ++lhs;
                --rhs;
            } else if (height[lhs] < height[rhs]) {
                ++lhs;
            } else {
                --rhs;
            }
        }
        return maxVol;
    }
};
