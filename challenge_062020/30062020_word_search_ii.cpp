class Solution {
public:
    bool isValid(const vector<vector<char>>& board,
                 const vector<vector<bool>>& used,
                 int r,
                 int c) {
        if (r < 0 || size(board) <= r ||
            c < 0 || size(board[0]) <= c) return false;
        return !used[r][c];
    }
    void helper(const vector<vector<char>>& board,
                vector<vector<bool>>& used,
                int r, 
                int c,
                string& curr,
                const string& target,
                unordered_set<string>& results) {
        curr.push_back(board[r][c]);
        used[r][c] = true;
        int curr_idx = size(curr) - 1;
        if (curr[curr_idx] != target[curr_idx]) {
            curr.pop_back();
            used[r][c] = false;
            return;
        }
        if (curr == target) {
            results.insert(curr);
            curr.pop_back();
            used[r][c] = false;
            return;
        }
        auto moves = vector<vector<int>>{{r-1,c},{r,c-1},{r+1,c},{r,c+1}};
        for (auto move : moves) {
            if (isValid(board, used, move[0], move[1])) {
                helper(board, used, move[0], move[1], curr, target, results);
            }
        }
        curr.pop_back();
        used[r][c] = false;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto result = vector<string>{};
        if (!size(board) || !size(board[0]) || !size(words)) return result;
        auto not_found = unordered_set<string>{};
        for (auto word : words) {
            not_found.insert(word);
        }
        auto res = unordered_set<string>{};
        auto used = vector<vector<bool>>(size(board), vector<bool>(size(board[0])));
        auto s = string{};
        for (auto r=0; r<size(board); ++r) {
            for (auto c=0; c<size(board[0]); ++c) {
                for (auto word : not_found) {
                    if (word[0] == board[r][c]) 
                        helper(board, used, r, c, s, word, res);
                }
                for (auto item : res) {
                    not_found.erase(item);
                }
            }
        }
        for (auto entry : res) {
            result.push_back(entry);
        }
        return result;
    }
};
