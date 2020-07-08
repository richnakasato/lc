/*
plan: iterate over cells, counting edges if adj cell is 0, or if at edge of map
time: row * col
space: 1
 */
class Solution {
public:
    bool countEdge(const vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || size(grid) <= r || c < 0 || size(grid[0]) <= c) return true;
        return grid[r][c] == 0;;
    }
    int countEdges(const vector<vector<int>>& grid, int r, int c) {
        auto count = 0;
        auto moves = vector<vector<int>>{{r-1,c},{r+1,c},{r,c-1},{r,c+1}};
        for (auto move : moves) {
            if (countEdge(grid, move[0], move[1])) ++count;
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        auto count = 0;
        for (auto r=0; r<size(grid); ++r) {
            for (auto c=0; c<size(grid[0]); ++c) {
                if (grid[r][c] == 1) count += countEdges(grid, r, c);
            }
        }
        return count;
    }
};
