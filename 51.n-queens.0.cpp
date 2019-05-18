/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (36.39%)
 * Total Accepted:    120.2K
 * Total Submissions: 330.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 *
 *
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 *
 * Example:
 *
 *
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 *
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 *
 *
 */
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
    bool is_safe(const std::vector<std::string>& board, int row, int col) {
        if (!board.size()) return true;
        for (auto c=0; c<board[0].size(); ++c) {
            if (board[row][c] != '.') return false;
        }
        auto max_r = board.size();
        auto max_c = board[0].size();
        auto diags = std::vector<std::tuple<int,int>>();
        diags.push_back(std::make_tuple(-1,-1));
        diags.push_back(std::make_tuple(-1,+1));
        diags.push_back(std::make_tuple(+1,+1));
        diags.push_back(std::make_tuple(+1,-1));
        for (const auto& d : diags) {
            auto r = row + std::get<0>(d);
            auto c = col + std::get<1>(d);
            while (0 <= r && r < max_r && 0 <= c && c < max_c) {
                if (board[r][c] != '.') {
                    return false;
                }
                r += std::get<0>(d);
                c += std::get<1>(d);
            }
        }
        return true;
    }

    void place(std::vector<std::string>& board, int row, int col) {
        board[row][col] = 'Q';
        return;
    }

    void unplace(std::vector<std::string>& board, int row, int col) {
        board[row][col] = '.';
        return;
    }

    void helper(std::vector<std::string>& board,
                int queen,
                int target,
                std::vector<std::vector<std::string>>& results)
    {
        if (queen == target) {
            results.push_back(board);
            return;
        }
        for (int row=0; row<board.size(); ++row) {
            if (is_safe(board, row, queen)) {
                place(board, row, queen);
                helper(board, queen+1, target, results);
                unplace(board, row, queen);
            }
        }
        return;
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        auto results = std::vector<std::vector<std::string>>();
        auto board = std::vector<std::string>(n, std::string(n, '.'));
        helper(board, 0, n, results);
        return results;
    }
};
