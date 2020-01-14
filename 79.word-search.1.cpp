/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (29.55%)
 * Total Accepted:    228.7K
 * Total Submissions: 773.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */
class Solution {
public:
    bool helper(std::vector<std::vector<char>>& board,
                std::vector<std::vector<bool>>& used,
                int row,
                int col,
                std::string& curr,
                int idx,
                std::string& word) {
        if (curr == word) return true;
        if (0 <= row && row < board.size() && 0 <= col && col < board[0].size() && !used[row][col]) {
            char letter = board[row][col];
            if (letter != word[idx]) return false;
            used[row][col] = true;
            curr.push_back(letter);
            if (helper(board, used, row-1, col, curr, idx+1, word)) return true;
            if (helper(board, used, row, col+1, curr, idx+1, word)) return true;
            if (helper(board, used, row+1, col, curr, idx+1, word)) return true;
            if (helper(board, used, row, col-1, curr, idx+1, word)) return true;
            curr.pop_back();
            used[row][col] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (!word.size()) return true;
        if (!board.size() || !board[0].size()) return false;
        std::vector<std::vector<bool>> used(board.size(), std::vector<bool>(board[0].size(), false));
        std::string curr;
        for (int row=0; row<board.size(); ++row) {
            for (int col=0; col<board[0].size(); ++col) {
                if (helper(board, used, row, col, curr, 0, word)) return true;
            }
        }
        return false;
    }
};
