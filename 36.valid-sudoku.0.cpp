/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (40.57%)
 * Total Accepted:    196.2K
 * Total Submissions: 483.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 *
 *
 *
 * A partially filled sudoku which is valid.
 *
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        return valid_rows(board) && valid_cols(board) && valid_quadrants(board);
    }

private:
    bool valid_rows(std::vector<std::vector<char>>& board)
    {
        for (size_t r=0; r<board.size(); ++r) {
            std::unordered_map<char,int> counts;
            for (size_t c=0; c<board[0].size(); ++c) {
                if (board[r][c] != '.') {
                    ++counts[board[r][c]];
                    if (counts[board[r][c]] > 1)
                        return false;
                }
            }
        }
        return true;
    }

    bool valid_cols(std::vector<std::vector<char>>& board)
    {
        for (size_t c=0; c<board.size(); ++c) {
            std::unordered_map<char,int> counts;
            for (size_t r=0; r<board[0].size(); ++r) {
                if (board[r][c] != '.') {
                    ++counts[board[r][c]];
                    if (counts[board[r][c]] > 1)
                        return false;
                }
            }
        }
        return true;
    }

    bool valid_quadrants(std::vector<std::vector<char>>& board)
    {
        size_t num_quads = 9;
        for (size_t q=0; q<num_quads; ++q) {
            std::unordered_map<char,int> counts;
            size_t r_start = q/3 * 3;
            size_t r_end = r_start + 3;
            for (size_t r=r_start; r<r_end; ++r) {
                size_t c_start = q%3 * 3;
                size_t c_end = c_start + 3;
                for (size_t c=c_start; c<c_end; ++c) {
                    if (board[r][c] != '.') {
                        ++counts[board[r][c]];
                        if (counts[board[r][c]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
