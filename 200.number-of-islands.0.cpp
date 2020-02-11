/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (39.01%)
 * Total Accepted:    260.6K
 * Total Submissions: 668.1K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 *
 * Example 1:
 *
 *
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 * Output: 3
 *
 */
class Solution {
public:
    bool valid(std::vector<std::vector<char>>& grid, int r, int c) {
        if (0 <= r && r < grid.size() && 0 <= c && c < grid[0].size()) {
            return true;
        }
        return false;
    }
    bool land(std::vector<std::vector<char>>& grid, int r, int c) {
        return grid[r][c] == '1';
    }
    void helper(std::vector<std::vector<char>>& grid,
                int r,
                int c) {
        if (!valid(grid, r, c)) return;
        if (!land(grid, r, c)) return;
        grid[r][c] = '0';
        helper(grid, r, c+1);
        helper(grid, r+1, c);
        helper(grid, r, c-1);
        helper(grid, r-1, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() < 1 || grid[0].size() < 1) return 0;
        int total = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (land(grid, r, c)) {
                    total += 1;
                    helper(grid, r, c);
                }
            }
        }
        return total;
    }
};
