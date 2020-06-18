// Plan: Backtracking. Do the opposite here, instead of trying to figure out if something is surrounded, only walk the border looking for 'O' and floodfill connected 'O's.  Then every 'O' that remains should be flipped to 'X' because it wasnt connected to a nonsurrounded square.
// Time : O(n*m)
// Space: O(n*m)

class Solution {
public:
    bool canMove(const vector<vector<char>>& board,  int r,  int c) {
        if (r < 0 or board.size() <= r) return false;
        if (c < 0 or board[r].size() <= c) return false;
        return board[r][c] == 'O';
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) return;
        int max_r = board.size();
        int max_c = board[0].size();
        auto q = queue<vector<int>>{};
        for (auto r=0; r<max_r; ++r) {
            if (canMove(board, r, 0)) q.push({r,0});
            if (canMove(board, r, max_c-1)) q.push({r,max_c-1});
        }
        for (auto c=0; c<max_c; ++c) {
            if (canMove(board, 0, c)) q.push({0,c});
            if (canMove(board, max_r-1, c)) q.push({max_r-1,c});
        }
        auto flip = board;
        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            auto r = temp[0];
            auto c = temp[1];
            flip[r][c] = 'X';
            auto moves = vector<vector<int>>{{r-1,c},{r+1,c},{r,c-1},{r,c+1}};
            for (auto move : moves) {
                auto next_r = move[0];
                auto next_c = move[1];
                if (canMove(flip, next_r, next_c)) {
                    q.push({next_r,next_c});
                }
            }
        }
        for (auto r=0; r<max_r; ++r) {
            for (auto c=0; c<max_c; ++c) {
                if (flip[r][c] == 'O' and board[r][c] == 'O') board[r][c] = 'X';
            }
        }
        return;
    }
};
