/*
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (38.21%)
 * Total Accepted:    174.9K
 * Total Submissions: 457.9K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output:
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output:
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 *
 *
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::unordered_set<int> rows;
        std::unordered_set<int> cols;
        for (int r=0; r<matrix.size(); ++r) {
            for (int c=0; c<matrix[0].size(); ++c) {
                if (!matrix[r][c]) {
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        }
        for (int r=0; r<matrix.size(); ++r) {
            for (int c=0; c<matrix[0].size(); ++c) {
                if (rows.find(r) != rows.end() || cols.find(c) != cols.end()) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};
