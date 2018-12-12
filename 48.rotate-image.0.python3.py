class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        top = left = 0
        bot = right = len(matrix) - 1
        while top < bot and left < right:
            sz = bot - top
            for _ in range(sz):
                temp = matrix[top][left]
                for i in range(sz):
                    matrix[top+i][left] = matrix[top+i+1][left]
                for i in range(sz):
                    matrix[bot][left+i] = matrix[bot][left+i+1]
                for i in range(sz):
                    matrix[bot-i][right] = matrix[bot-i-1][right]
                for i in range(sz):
                    if right-i-1 == left:
                        matrix[top][right-i] = temp
                    else:
                        matrix[top][right-i] = matrix[top][right-i-1]
            top, left = top+1, left+1
            bot, right = bot-1, right-1
