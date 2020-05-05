class Solution {
public:
    bool canMove(vector<vector<char>>& grid, int r, int c) {
        return 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size();
    }
    bool isLand(vector<vector<char>>& grid, int r, int c) {
        return grid[r][c] == '1';
    }
    void helper(vector<vector<char>>& grid, int r, int c) {
        if (!canMove(grid, r, c)) return;
        if (!isLand(grid, r, c)) return;
        grid[r][c] = '0';
        helper(grid, r-1, c);
        helper(grid, r+1, c);
        helper(grid, r, c-1);
        helper(grid, r, c+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int count = 0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (isLand(grid, r, c)) {
                    ++count;
                    helper(grid, r, c);
                }
            }
        }
        return count;
    }
};
