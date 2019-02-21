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
#include <algorithm>
#include <tuple>
#include <vector>

class Solution {
public:
    bool is_valid(std::vector<std::vector<char>>& board,
                  std::tuple<int,int> pos)
    {
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        if (0 <= r && r < board.size() && 0 <= c && c < board[0].size()) {
            return true;
        }
        return false;
    }

    bool is_avail(std::vector<std::vector<bool>>& avail,
                  std::tuple<int,int> pos)
    {
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        return avail[r][c];
    }

    bool helper(std::vector<std::vector<char>>& board,
                std::vector<std::vector<bool>> avail,
                std::tuple<int,int> pos,
                std::string word,
                int idx)
    {
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        char letter = word[idx++];
        avail[r][c] = false;
        if (board[r][c] != letter) return false;
        else if (idx == word.size()) {
            return true;
        }
        std::vector<std::tuple<int,int>> moves;
        moves.push_back(std::make_tuple(r-1,c));
        moves.push_back(std::make_tuple(r+1,c));
        moves.push_back(std::make_tuple(r,c-1));
        moves.push_back(std::make_tuple(r,c+1));
        for (const auto& move : moves) {
            if (is_valid(board, move) && is_avail(avail, move)) {
                if (helper(board, avail, move, word, idx)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        std::vector<std::vector<bool>> avail(board.size(),
                                             std::vector<bool>(board[0].size(), true));
        int idx = 0;
        for (int r=0; r<board.size(); ++r) {
            for (int c=0; c<board[0].size(); ++c) {
                if (board[r][c] == word[0]) {
                    if(helper(board, avail, std::make_tuple(r,c), word, idx)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
