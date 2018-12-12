#
# [7] Reverse Integer
#
# https://leetcode.com/problems/reverse-integer/description/
#
# algorithms
# Easy (24.39%)
# Total Accepted:    408.4K
# Total Submissions: 1.7M
# Testcase Example:  '123'
#
# Given a 32-bit signed integer, reverse digits of an integer.
#
# Example 1:
#
#
# Input: 123
# Output: 321
#
#
# Example 2:
#
#
# Input: -123
# Output: -321
#
#
# Example 3:
#
#
# Input: 120
# Output: 21
#
#
# Note:
# Assume we are dealing with an environment which could only store integers
# within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
# this problem, assume that your function returns 0 when the reversed integer
# overflows.
#
#
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        is_neg = x < 0
        x = abs(x)
        rev_x = int(str(x)[::-1])
        if is_neg:
            rev_x = -rev_x
        return rev_x if int(-0x80000000) <= rev_x <= int(0x7FFFFFFF) else 0

