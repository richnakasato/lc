#
# [485] Max Consecutive Ones
#
# https://leetcode.com/problems/max-consecutive-ones/description/
#
# algorithms
# Easy (53.86%)
# Total Accepted:    110.2K
# Total Submissions: 204.5K
# Testcase Example:  '[1,0,1,1,0,1]'
#
# Given a binary array, find the maximum number of consecutive 1s in this
# array.
#
# Example 1:
#
# Input: [1,1,0,1,1,1]
# Output: 3
# Explanation: The first two digits or the last three digits are consecutive
# 1s.
# ⁠   The maximum number of consecutive 1s is 3.
#
#
#
# Note:
#
# The input array will only contain 0 and 1.
# The length of input array is a positive integer and will not exceed 10,000
#
#
#
class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        groups = list()
        count = 0
        for num in nums:
            if num == 1:
                count += 1
            else:
                if count > 0:
                    groups.append(count)
                count = 0
        if count > 0:
            groups.append(count)
        if len(groups):
            return max(groups)
        else:
            return 0
