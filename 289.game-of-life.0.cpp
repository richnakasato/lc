/*
 * [289] Game of Life
 *
 * https://leetcode.com/problems/game-of-life/description/
 *
 * algorithms
 * Medium (41.38%)
 * Total Accepted:    90.2K
 * Total Submissions: 218K
 * Testcase Example:  '[[0,1,0],[0,0,1],[1,1,1],[0,0,0]]'
 *
 * According to the Wikipedia's article: "The Game of Life, also known simply
 * as Life, is a cellular automaton devised by the British mathematician John
 * Horton Conway in 1970."
 *
 * Given a board with m by n cells, each cell has an initial state live (1) or
 * dead (0). Each cell interacts with its eight neighbors (horizontal,
 * vertical, diagonal) using the following four rules (taken from the above
 * Wikipedia article):
 *
 *
 * Any live cell with fewer than two live neighbors dies, as if caused by
 * under-population.
 * Any live cell with two or three live neighbors lives on to the next
 * generation.
 * Any live cell with more than three live neighbors dies, as if by
 * over-population..
 * Any dead cell with exactly three live neighbors becomes a live cell, as if
 * by reproduction.
 *
 *
 * Write a function to compute the next state (after one update) of the board
 * given its current state. The next state is created by applying the above
 * rules simultaneously to every cell in the current state, where births and
 * deaths occur simultaneously.
 *
 * Example:
 *
 *
 * Input:
 * [
 * [0,1,0],
 * [0,0,1],
 * [1,1,1],
 * [0,0,0]
 * ]
 * Output:
 * [
 * [0,0,0],
 * [1,0,1],
 * [0,1,1],
 * [0,1,0]
 * ]
 *
 *
 * Follow up:
 *
 *
 * Could you solve it in-place? Remember that the board needs to be updated at
 * the same time: You cannot update some cells first and then use their updated
 * values to update other cells.
 * In this question, we represent the board using a 2D array. In principle, the
 * board is infinite, which would cause problems when the active area
 * encroaches the border of the array. How would you address these problems?
 *
 *
 */
class Solution {
public:
    bool valid_pos(const std::vector<std::vector<int>>& board,
                   const std::tuple<size_t,size_t>& pos)
    {
        int row = std::get<0>(pos);
        int elem = std::get<1>(pos);
        return 0 <= row && row < board.size()
            && 0 <= elem && elem < board[0].size();
    }

    int neighbor_count(const std::vector<std::vector<int>>& board,
                       const std::tuple<size_t,size_t>& pos)
    {
        int neighbor_count = 0;
        int row = std::get<0>(pos);
        int elem = std::get<1>(pos);
        for (int i=row-1; i<=row+1; ++i) {
            for (int j=elem-1; j<=elem+1; ++j) {
                auto pos = std::make_tuple(i,j);
                neighbor_count += valid_pos(board, pos) && board[i][j] ? 1 : 0;
            }
        }
        neighbor_count -= board[row][elem];
        return neighbor_count;
    }

    int new_state(const int& neighbor_count, int curr_state)
    {
        if (neighbor_count < 2 && curr_state) return 0;
        if (neighbor_count == 3 && !curr_state) return 1;
        if (neighbor_count > 3 && curr_state) return 0;
        if ((neighbor_count == 2 || neighbor_count == 3)
                && curr_state) return 1;
        return 0;
    }

    void gameOfLife(vector<vector<int>>& board) {

        std::vector<std::vector<int>> new_board = board;
        for (size_t row=0; row<board.size(); ++row) {
            for (size_t elem=0; elem<board[0].size(); ++elem) {
                int neighbors = neighbor_count(board, std::make_tuple(row,elem);
                int curr_state = board[row][elem];
                new_board[row][elem] = new_state(neighbors, curr_state);
            }
        }
        for (size_t row=0; row<board.size(); ++row) {
            for (size_t elem=0; elem<board[0].size(); ++elem) {
                board[row][elem] = new_board[row][elem];
            }
        }
    }
};
