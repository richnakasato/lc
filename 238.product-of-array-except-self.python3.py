#
# [238] Product of Array Except Self
#
# https://leetcode.com/problems/product-of-array-except-self/description/
#
# algorithms
# Medium (52.72%)
# Total Accepted:    202K
# Total Submissions: 383.1K
# Testcase Example:  '[1,2,3,4]'
#
# Given an array nums of n integers where n > 1,  return an array output such
# that output[i] is equal to the product of all the elements of nums except
# nums[i].
# 
# Example:
# 
# 
# Input:  [1,2,3,4]
# Output: [24,12,8,6]
# 
# 
# Note: Please solve it without division and in O(n).
# 
# Follow up:
# Could you solve it with constant space complexity? (The output array does not
# count as extra space for the purpose of space complexity analysis.)
# 
#
class Solution:
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
