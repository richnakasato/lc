/*
plan: bfs, track "levels"
*/

class Solution {
public:
    bool canMove(const vector<vector<int>>& grid, const vector<vector<bool>>& processed, int r, int c) {
        if (r < 0 || size(grid) <= r || c < 0 || size(grid[0]) <= c) return false;
        return grid[r][c] == 1 && !processed[r][c];
    }
    int orangesRotting(vector<vector<int>>& grid) {
        auto result = 0;
        if (!size(grid) || !size(grid[0])) return result;
        auto processed = vector<vector<bool>>(size(grid), vector<bool>(size(grid[0]), false));
        auto q = queue<tuple<int,int,int>>{};
        for (auto r=0; r<size(grid); ++r) {
            for (auto c=0; c<size(grid[0]); ++c) {
                if (grid[r][c] == 2) {
                    q.push(tuple<int,int,int>{r,c,0});
                    processed[r][c] = true;
                }
            }
        }
        while (size(q)) {
            auto temp = q.front(); q.pop();
            auto row = get<0>(temp);
            auto col = get<1>(temp);
            auto lvl = get<2>(temp);
            result = max(result,lvl);
            auto moves = {tuple<int,int>{row-1,col},
                          tuple<int,int>{row+1,col},
                          tuple<int,int>{row,col-1},
                          tuple<int,int>{row,col+1}};
            for (auto move : moves) {
                auto next_row = get<0>(move);
                auto next_col = get<1>(move);
                if (canMove(grid, processed, next_row, next_col)) {
                    processed[next_row][next_col] = true;
                    q.push(tuple<int,int,int>{next_row, next_col, lvl+1});
                }
            }
        }
        for (auto r=0; r<size(grid); ++r) {
            for (auto c=0; c<size(grid[0]); ++c) {
                if (grid[r][c] == 1 && !processed[r][c]) return -1;
            }
        }
        return result;
    }
};
