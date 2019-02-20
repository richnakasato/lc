#
# [79] Word Search
#
# https://leetcode.com/problems/word-search/description/
#
# algorithms
# Medium (29.55%)
# Total Accepted:    228.7K
# Total Submissions: 773.8K
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# Given a 2D board and a word, find if the word exists in the grid.
#
# The word can be constructed from letters of sequentially adjacent cell, where
# "adjacent" cells are those horizontally or vertically neighboring. The same
# letter cell may not be used more than once.
#
# Example:
#
#
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
#
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
#
#
#
import copy

class Solution:
    def is_valid(self, board, pos):
        r,c = pos
        if 0 <= r < len(board) and 0 <= c < len(board[0]):
            return True
        return False

    def helper(self, board, avail, pos, word, idx, results):
        letter = word[idx]
        r,c = pos
        if avail[r][c] and letter == board[r][c]:
            idx += 1
            if idx == len(word):
                results.append(True)
                return
            avail[r][c] = False
            if self.is_valid(board, (r-1,c)):
                new_avail = copy.deepcopy(avail)
                self.helper(board, new_avail, (r-1,c), word, idx+1, results)
            if self.is_valid(board, (r+1,c)):
                new_avail = copy.deepcopy(avail)
                self.helper(board, new_avail, (r+1,c), word, idx+1, results)
            if self.is_valid(board, (r,c-1)):
                new_avail = copy.deepcopy(avail)
                self.helper(board, new_avail, (r,c-1), word, idx+1, results)
            if self.is_valid(board, (r,c+1)):
                new_avail = copy.deepcopy(avail)
                self.helper(board, new_avail, (r,c+1), word, idx+1, results)
        return

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        avail = [[True for col in row] for row in board]
        idx = 0
        results = list()
        for r in range(len(board)):
            for c in range(len(board[0])):
                self.helper(board, avail, (r,c), word, idx, results)
        return any(results)

