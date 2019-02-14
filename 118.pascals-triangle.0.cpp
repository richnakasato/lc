/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (43.18%)
 * Total Accepted:    209.5K
 * Total Submissions: 485.2K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 *
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 *
 * Example:
 *
 *
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 *
 *
 */
#include <vector>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pascal;
        for (size_t i=0; i<numRows; ++i) {
            std::vector<int> row(i+1);
            row[0] = 1;
            row[row.size()-1] = 1;
            pascal.push_back(row);
        }
        for (size_t i=2; i<numRows; ++i) {
            for (size_t j=1; j<pascal[i].size()-1; ++j) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};
