#
# [739] Daily Temperatures
#
# https://leetcode.com/problems/daily-temperatures/description/
#
# algorithms
# Medium (56.96%)
# Total Accepted:    39.9K
# Total Submissions: 70.1K
# Testcase Example:  '[73,74,75,71,69,72,76,73]'
#
#
# Given a list of daily temperatures T, return a list such that, for each day
# in the input, tells you how many days you would have to wait until a warmer
# temperature.  If there is no future day for which this is possible, put 0
# instead.
#
# For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
# 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
#
#
# Note:
# The length of temperatures will be in the range [1, 30000].
# Each temperature will be an integer in the range [30, 100].
#
#
class Solution:
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        unsolved = list()
        results = [0] * len(T)
        for curr_idx, curr_temp in enumerate(T):
            while unsolved and unsolved[-1][1] < curr_temp:
                unsolved_idx, unsolved_temp = unsolved.pop()
                results[unsolved_idx] = curr_idx - unsolved_idx
            to_solve = curr_idx, curr_temp
            unsolved.append(to_solve)
        return results
