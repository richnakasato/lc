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
        # naive brute force version (i.e. my version)
        count = 0
        for start in range(len(s)):
            for end in range(start+1, len(s+1)):
                curr = s[start:end]
                if curr == curr[::-1]:
                    count += 1
        return count

    def countSubstrings2(self, s):
        # smart brute force - LC solution version (had to look this one up)
        count = 0
        n = len(s)
        for center in range(2*n-1):
            left = center//2
            right = left + center%2
            if left >= 0 and right < n and s[left] == s[right]:
                count += 1
                left -= 1
                right += 1
        return count
