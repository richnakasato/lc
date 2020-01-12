/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (28.83%)
 * Total Accepted:    189.5K
 * Total Submissions: 657.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        if (!matrix.size()) return result;
        int top = 0;
        int bot = matrix.size() - 1;
        int lhs = 0;
        int rhs = matrix[0].size() - 1;
        int dir = 0;
        while (top <= bot && lhs <= rhs) {
            dir %= 4;
            if (dir == 0) {
                for (int i=lhs; i<=rhs; ++i) {
                    result.push_back(matrix[top][i]);
                }
                ++top;
            } else if (dir == 1) {
                for (int i=top; i<=bot; ++i) {
                    result.push_back(matrix[i][rhs]);
                }
                --rhs;
            } else if (dir == 2) {
                for (int i=rhs; i>=lhs; --i) {
                    result.push_back(matrix[bot][i]);
                }
                --bot;
            } else {
                for (int i=bot; i>=top; --i) {
                    result.push_back(matrix[i][lhs]);
                }
                ++lhs;
            }
            ++dir;
        }
        return result;
    }
};
