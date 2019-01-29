#
# [54] Spiral Matrix
#
# https://leetcode.com/problems/spiral-matrix/description/
#
# algorithms
# Medium (28.83%)
# Total Accepted:    189.5K
# Total Submissions: 657.1K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# Given a matrix of m x n elements (m rows, n columns), return all elements of
# the matrix in spiral order.
#
# Example 1:
#
#
# Input:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 4, 5, 6 ],
# ⁠[ 7, 8, 9 ]
# ]
# Output: [1,2,3,6,9,8,7,4,5]
#
#
# Example 2:
#
# Input:
# [
# ⁠ [1, 2, 3, 4],
# ⁠ [5, 6, 7, 8],
# ⁠ [9,10,11,12]
# ]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#
#
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not len(matrix):
            return []
        result = list()
        top = left = 0
        bot, right = len(matrix), len(matrix[0])
        direction = 0 # 0==right, 1==down, 2==left, 3==up
        while top < bot and left < right:
            if direction % 4 == 0: # right
                for i in range(left, right):
                    result.append(matrix[top][i])
                top += 1
            elif direction % 4 == 1: # down
                for i in range(top, bot):
                    result.append(matrix[i][right-1])
                right -= 1
            elif direction % 4 == 2: # left
                for i in reversed(range(left, right)):
                    result.append(matrix[bot-1][i])
                bot -= 1
            else: # up
                for i in reversed(range(top, bot)):
                    result.append(matrix[i][left])
                left += 1
            direction += 1
        return result
