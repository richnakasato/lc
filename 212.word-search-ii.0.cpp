/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (26.63%)
 * Total Accepted:    88.1K
 * Total Submissions: 330.9K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 * Example:
 *
 *
 * Input:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 *
 * Output: ["eat","oath"]
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */
#include <tuple>
#include <unordered_set>

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        std::unordered_set<std::string> found;
        std::vector<std::string> results;
        for (size_t word=0; word<words.size(); ++word) {
            for (size_t row=0; row<board.size(); ++row) {
                for (size_t col=0; col<board[0].size(); ++col) {
                    int curr_idx = 0;
                    if (board[row][col] == words[word][curr_idx]) {
                        std::tuple<int,int> curr_pos = std::make_tuple(row, col);
                        helper(board, curr_pos, words[word], curr_idx, results, found);
                    }
                }
            }
        }
        return results;
    }
private:
    void helper(std::vector<std::vector<char>>& board,
                std::tuple<int,int> pos,
                const std::string& word,
                int idx,
                std::vector<std::string>& results,
                std::unordered_set<std::string>& found)
    {
        if (found.find(word) != found.end()) return;
        if (idx == word.size()-1) {
            found.insert(word);
            results.push_back(word);
        }
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        char temp = board[r][c];
        board[r][c] = '-';
        std::vector<std::tuple<int,int>> moves {std::make_tuple(r-1,c),
                                                std::make_tuple(r+1,c),
                                                std::make_tuple(r,c-1),
                                                std::make_tuple(r,c+1)};
        for (const auto& move : moves) {
            if (is_valid(board, move) && has_letter(board, move, word[idx+1]))
                helper(board, move, word, idx+1, results, found);
        }
        board[r][c] = temp;
    }

    bool is_valid(std::vector<std::vector<char>>& board,
                  std::tuple<int,int> pos)
    {
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        if (0 <= r && r < board.size() && 0 <= c && c < board[0].size())
            return true;
        return false;
    }

    bool has_letter(std::vector<std::vector<char>>& board,
                    std::tuple<int,int> pos,
                    char letter)
    {
        int r = std::get<0>(pos);
        int c = std::get<1>(pos);
        return board[r][c] == letter;
    }
};
