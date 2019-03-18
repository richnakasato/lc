#
# [228] Summary Ranges
#
# https://leetcode.com/problems/summary-ranges/description/
#
# algorithms
# Medium (34.37%)
# Total Accepted:    117.1K
# Total Submissions: 340.7K
# Testcase Example:  '[0,1,2,4,5,7]'
#
# Given a sorted integer array without duplicates, return the summary of its
# ranges.
#
# Example 1:
#
#
# Input:  [0,1,2,4,5,7]
# Output: ["0->2","4->5","7"]
# Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
#
#
# Example 2:
#
#
# Input:  [0,2,3,4,6,8,9]
# Output: ["0","2->4","6","8->9"]
# Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
#
#
#
class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not len(nums):
            return list()
        start = end = nums[0]
        result = list()
        for i in range(1, len(nums)):
            if nums[i] == end + 1:
                end = nums[i]
            else:
                result.append(self.get_str(start, end))
                start = nums[i]
                end = nums[i]
        result.append(self.get_str(start, end))
        return result


    def get_str(self, start, end):
        if start == end:
            return str(start)
        else:
            return str(start) + "->" + str(end)

