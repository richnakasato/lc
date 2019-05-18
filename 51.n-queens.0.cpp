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
    bool is_safe(std::vector<std::string> board, int row, int col) {
        if (!board.size()) return true;
        if (board[row][col] != '.') return false;
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

    void place(std::vector<std::string> board, int row, int col) {
        board[row][col] = 'Q';
        return;
    }

    void unplace(std::vector<std::string> board, int row, int col) {
        board[row][col] = '.';
        return;
    }

    std::string join_board(std::vector<std::string> board) {
        std::string res;
        for (const auto& row : board) {
            res += row;
        }
        return res;
    }

    std::vector<std::string> split_board(std::string board, int n) {
        std::vector<std::string> res;
        for (int i=0; i<board.size(); i+=n) {
            res.push_back(board.substr(i,n));
        }
        return res;
    }

    void helper(std::vector<std::string>& queens,
                int count,
                int target,
                std::unordered_set<std::string>& results)
    {
        if (count == target) {
            results.insert(join_board(queens));
            return;
        }
        if (count + avail < target) return;
        for (int r=0; r<queens.size(); ++r) {
            for (int c=0; c<queens[r].size(); ++c) {
                if (queens[r][c] != 'Q' && !attacks[r][c]) {
                    queens[r][c] = 'Q';
                    auto new_attacks = set_attacks(queens, attacks, r, c);
                    helper(count+1, target, avail - 1 - new_attacks.size(),
                           queens, attacks, results);
                    unset_attacks(attacks, new_attacks);
                    queens[r][c] = '.';
                }
            }
        }
        return;
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        int count = 0;
        std::vector<std::string> queens(n, std::string(n, '.'));
        std::vector<std::vector<bool>> attacks(n, std::vector(n, false));
        std::unordered_set<std::string> results;
        if (n < 1) return std::vector<std::vector<std::string>>();
        helper(count, n, n*n, queens, attacks, results);
        std::vector<std::vector<std::string>> temp;
        for (const auto& e : results) {
            temp.push_back(split_board(e, n));
        }
        return temp;
    }
};
