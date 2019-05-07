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
#include <vector>
class Solution {
    void unset_attacks(std::vector<std::vector<bool>>& attacks,
                       std::vector<std::tuple<int,int>>& list_of_attacks)
    {
        if (!list_of_attacks.size()) return;
        for (const auto& attack : list_of_attacks) {
            int row = std::get<0>(attack);
            int col = std::get<1>(attack);
            attacks[row][col] = false;
        }
    }
    std::vector<std::tuple<int,int>> set_attacks(
            std::vector<std::string>& queens,
            std::vector<std::vector<bool>>& attacks,
            int row, int col) {
        std::vector<std::tuple<int,int>> results;
        for (int r=0; r<queens.size(); ++r) {
            if (queens[r][col] != 'Q' && !attacks[r][col]) {
                attacks[r][col] = true;
                results.push_back(std::make_tuple(r, col));
            }
        }
        for (int c=0; c<queens[row].size(); ++c) {
            if (queens[row][c] != 'Q' && !attacks[row][c])
            {
                attacks[row][c] = true;
                results.push_back(std::make_tuple(row, c));
            }
        }
        int max_r = queens.size();
        int max_c = queens[row].size();
        int r = row-1;
        int c = col-1;
        while (0 <= r && r < max_r && 0 <= c && c < max_c) {
            if (queens[r][c] != 'Q' && !attacks[r][c])
            {
                attacks[r][c] = true;
                results.push_back(std::make_tuple(r, c));
            }
            --r;
            --c;
        }
        r = row-1;
        c = col+1;
        while (0 <= r && r < max_r && 0 <= c && c < max_c) {
            if (queens[r][c] != 'Q' && !attacks[r][c])
            {
                attacks[r][c] = true;
                results.push_back(std::make_tuple(r, c));
            }
            --r;
            ++c;
        }
        r = row+1;
        c = col+1;
        while (0 <= r && r < max_r && 0 <= c && c < max_c) {
            if (queens[r][c] != 'Q' && !attacks[r][c])
            {
                attacks[r][c] = true;
                results.push_back(std::make_tuple(r, c));
            }
            ++r;
            ++c;
        }
        r = row+1;
        c = col-1;
        while (0 <= r && r < max_r && 0 <= c && c < max_c) {
            if (queens[r][c] != 'Q' && !attacks[r][c])
            {
                attacks[r][c] = true;
                results.push_back(std::make_tuple(r, c));
            }
            ++r;
            --c;
        }
        return results;
    }
    void helper(int count,
                int target,
                int avail,
                std::vector<std::string>& queens,
                std::vector<std::vector<bool>>& attacks,
                std::vector<std::vector<std::string>>& results) {
        if (count == target) {
            results.push_back(queens);
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
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        int count = 0;
        std::vector<std::string> queens(n, std::string(n, '.'));
        std::vector<std::vector<bool>> attacks(n, std::vector(n, false));
        std::vector<std::vector<std::string>> results;
        if (n < 1) return results;
        helper(count, n, n*n, queens, attacks, results);
        return results;
    }
};
