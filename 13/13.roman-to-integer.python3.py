#
# [13] Roman to Integer
#
# https://leetcode.com/problems/roman-to-integer/description/
#
# algorithms
# Easy (48.31%)
# Total Accepted:    233.2K
# Total Submissions: 482.8K
# Testcase Example:  '"III"'
#
# Roman numerals are represented by seven different symbols: I, V, X, L, C, D
# and M.
#
#
# Symbol       Value
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
#
# For example, two is written as II in Roman numeral, just two one's added
# together. Twelve is written as, XII, which is simply X + II. The number
# twenty seven is written as XXVII, which is XX + V + II.
#
# Roman numerals are usually written largest to smallest from left to right.
# However, the numeral for four is not IIII. Instead, the number four is
# written as IV. Because the one is before the five we subtract it making four.
# The same principle applies to the number nine, which is written as IX. There
# are six instances where subtraction is used:
#
#
# I can be placed before V (5) and X (10) to make 4 and 9. 
# X can be placed before L (50) and C (100) to make 40 and 90. 
# C can be placed before D (500) and M (1000) to make 400 and 900.
#
#
# Given a roman numeral, convert it to an integer. Input is guaranteed to be
# within the range from 1 to 3999.
#
# Example 1:
#
#
# Input: "III"
# Output: 3
#
# Example 2:
#
#
# Input: "IV"
# Output: 4
#
# Example 3:
#
#
# Input: "IX"
# Output: 9
#
# Example 4:
#
#
# Input: "LVIII"
# Output: 58
# Explanation: C = 100, L = 50, XXX = 30 and III = 3.
#
#
# Example 5:
#
#
# Input: "MCMXCIV"
# Output: 1994
# Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
#
#
s_keys = ['IV', 'IX', 'XL', 'XC', 'CD', 'CM']
s_vals = [4, 9, 40, 90, 400, 900]
s_dict = dict(zip(s_keys, s_vals))

n_keys = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
n_vals = [1, 5, 10, 50, 100, 500, 1000]
n_dict = dict(zip(n_keys, n_vals))

class Solution:
    def getRomanNumAndNextIdx(s, i):
        if i == len(s)-1:
            return n_dict[s[i]], len(s)
        elif s[i]+s[i+1] in s_dict:
            return s_dict[s[i]+s[i+1]], i+2
        else:
            return n_dict[s[i]], i+1

    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        i = 0
        val = 0
        while i < len(s):
            temp, i = Solution.getRomanNumAndNextIdx(s, i)
            val += temp
        return val
