#
# [742] To Lower Case
#
# https://leetcode.com/problems/to-lower-case/description/
#
# algorithms
# Easy (74.36%)
# Total Accepted:    40.9K
# Total Submissions: 54.9K
# Testcase Example:  '"Hello"'
#
# Implement function ToLowerCase() that has a string parameter str, and returns
# the same string in lowercase.
#
#
#
#
# Example 1:
#
#
# Input: "Hello"
# Output: "hello"
#
#
#
# Example 2:
#
#
# Input: "here"
# Output: "here"
#
#
#
# Example 3:
#
#
# Input: "LOVELY"
# Output: "lovely"
#
#
#
#
#
#
'''
Takeaways:
- opposite of ord() is chr()
- capital letters come BEFORE lowercase letters (i.e. ord('A') < ord('a'))

'''
class Solution:
    def toLowerCase(self, str):
        """
        :type str: str
        :rtype: str
        """
        upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        lower = "abcdefghijklmnopqrstuvwxyz"
        out = list()
        for char in str:
            if char in upper:
                idx = upper.find(char)
                out.append(lower[idx])
            else:
                out.append(char)
        return ''.join(out)
