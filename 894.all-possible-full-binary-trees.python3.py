#
# [930] All Possible Full Binary Trees
#
# https://leetcode.com/problems/all-possible-full-binary-trees/description/
#
# algorithms
# Medium (66.65%)
# Total Accepted:    9.1K
# Total Submissions: 13.6K
# Testcase Example:  '7'
#
# A full binary tree is a binary tree where each node has exactly 0 or 2
# children.
# 
# Return a list of all possible full binary trees with N nodes.  Each element
# of the answer is the root node of one possible tree.
# 
# Each node of each tree in the answer must have node.val = 0.
# 
# You may return the final list of trees in any order.
# 
# 
# 
# Example 1:
# 
# 
# Input: 7
# Output:
# [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
# Explanation:
# 
# 
# 
# 
# 
# Note:
# 
# 
# 1 <= N <= 20
# 
# 
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        
