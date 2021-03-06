#
# [929] Groups of Special-Equivalent Strings
#
# https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
#
# algorithms
# Easy (60.51%)
# Total Accepted:    7.4K
# Total Submissions: 12.2K
# Testcase Example:  '["a","b","c","a","c","c"]'
#
# You are given an array A of strings.
#
# Two strings S and T are special-equivalent if after any number of moves, S ==
# T.
#
# A move consists of choosing two indices i and j with i % 2 == j % 2, and
# swapping S[i] with S[j].
#
# Now, a group of special-equivalent strings from A is a non-empty subset S of
# A such that any string not in S is not special-equivalent with any string in
# S.
#
# Return the number of groups of special-equivalent strings from A.
#
#
#
#
#
#
#
# Example 1:
#
#
# Input: ["a","b","c","a","c","c"]
# Output: 3
# Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
#
#
#
# Example 2:
#
#
# Input: ["aa","bb","ab","ba"]
# Output: 4
# Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
#
#
#
# Example 3:
#
#
# Input: ["abc","acb","bac","bca","cab","cba"]
# Output: 3
# Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
#
#
#
# Example 4:
#
#
# Input: ["abcd","cdab","adcb","cbad"]
# Output: 1
# Explanation: 1 group ["abcd","cdab","adcb","cbad"]
#
#
#
#
# Note:
#
#
# 1 <= A.length <= 1000
# 1 <= A[i].length <= 20
# All A[i] have the same length.
# All A[i] consist of only lowercase letters.
#
#
#
#
#
#
#
class Solution:
    def numSpecialEquivGroups(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        # TODO: error handling
        equiv = list()
        for word in A:
            even = [0 for x in range(26)]
            odd = [0 for x in range(26)]
            for idx in range(len(word)):
                char = word[idx]
                if not idx%2:
                    even[ord(char) - ord('a')]+=1
                else:
                    odd[ord(char) - ord('a')]+=1
            equiv.append(tuple(even+odd))
        return len(set(equiv))

