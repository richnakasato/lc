#
# [807] Custom Sort String
#
# https://leetcode.com/problems/custom-sort-string/description/
#
# algorithms
# Medium (59.59%)
# Total Accepted:    20.8K
# Total Submissions: 35K
# Testcase Example:  '"cba"\n"abcd"'
#
# S and T are strings composed of lowercase letters. In S, no letter occurs
# more than once.
#
# S was sorted in some custom order previously. We want to permute the
# characters of T so that they match the order that S was sorted. More
# specifically, if x occurs before y in S, then x should occur before y in the
# returned string.
#
# Return any permutation of T (as a string) that satisfies this property.
#
#
# Example :
# Input:
# S = "cba"
# T = "abcd"
# Output: "cbad"
# Explanation:
# "a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b",
# and "a".
# Since "d" does not appear in S, it can be at any position in T. "dcba",
# "cdba", "cbda" are also valid outputs.
#
#
#
#
# Note:
#
#
# S has length at most 26, and no character is repeated in S.
# T has length at most 200.
# S and T consist of lowercase letters only.
#
#
#
class Solution:
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        s_dict = dict()
        t_sort = list()
        t_unsort = list()
        counter = 0
        for char in S:
            s_dict[char] = counter
            counter += 1
        for char in T:
            if char in s_dict:
                t_sort.append(s_dict[char])
            else:
                t_unsort.append(char)
        t_sort.sort()
        inv_s_dict = {v: k for k, v in s_dict.items()}
        t_char_sort = [inv_s_dict[n] for n in t_sort]
        return ''.join(t_char_sort + t_unsort)
