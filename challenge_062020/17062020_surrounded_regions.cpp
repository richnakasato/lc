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
    void helper(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'X';
        auto moves = vector<vector<int>>{{r-1,c},{r+1,c},{r,c-1},{r,c+1}};
        for (auto move : moves) {
            auto next_r = move[0];
            auto next_c = move[1];
            if (canMove(board, next_r, next_c)) helper(board, next_r, next_c);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) return;
        int max_r = board.size();
        int max_c = board[0].size();
        auto flip = board;
        for (auto r=0; r<max_r; ++r) {
            if (canMove(flip, r, 0)) helper(flip, r, 0);
            if (canMove(flip, r, max_c-1)) helper(flip, r, max_c-1);
        }
        for (auto c=0; c<max_c; ++c) {
            if (canMove(flip, 0, c)) helper(flip, 0, c);
            if (canMove(flip, max_r-1, c)) helper(flip, max_r-1, c);
        }
        for (auto r=0; r<max_r; ++r) {
            for (auto c=0; c<max_c; ++c) {
                if (flip[r][c] == 'O' and board[r][c] == 'O') board[r][c] = 'X';
            }
        }
        return;
    }
};
