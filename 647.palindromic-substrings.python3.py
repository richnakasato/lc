#
# [647] Palindromic Substrings
#
# https://leetcode.com/problems/palindromic-substrings/description/
#
# algorithms
# Medium (54.53%)
# Total Accepted:    66K
# Total Submissions: 120.9K
# Testcase Example:  '"abc"'
#
# 
# Given a string, your task is to count how many palindromic substrings in this
# string.
# 
# 
# 
# The substrings with different start indexes or end indexes are counted as
# different substrings even they consist of same characters. 
# 
# 
# Example 1:
# 
# Input: "abc"
# Output: 3
# Explanation: Three palindromic strings: "a", "b", "c".
# 
# 
# 
# Example 2:
# 
# Input: "aaa"
# Output: 6
# Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
# 
# 
# 
# Note:
# 
# The input string length won't exceed 1000.
# 
# 
#
class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        
