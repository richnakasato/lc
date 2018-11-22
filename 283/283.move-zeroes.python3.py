#
# [283] Move Zeroes
#
# https://leetcode.com/problems/move-zeroes/description/
#
# algorithms
# Easy (52.71%)
# Total Accepted:    373.2K
# Total Submissions: 707.5K
# Testcase Example:  '[0,1,0,3,12]'
#
# Given an array nums, write a function to move all 0's to the end of it while
# maintaining the relative order of the non-zero elements.
#
# Example:
#
#
# Input: [0,1,0,3,12]
# Output: [1,3,12,0,0]
#
# Note:
#
#
# You must do this in-place without making a copy of the array.
# Minimize the total number of operations.
#
#
from collections import deque

class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        q = deque()
        for num in nums:
            if num != 0:
                q.append(num)
        for idx in range(len(nums)):
            if len(q):
                nums[idx] = q.popleft()
            else:
                nums[idx] = 0


    def moveZeroes_2(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        src = dst = 0
        done = False
        while not done:
            while src < len(nums) and nums[src] != 0:
                src += 1
            dst = src + 1
            while dst < len(nums) and nums[dst] == 0:
                dst += 1
            if src < len(nums) and dst < len(nums):
                nums[src], nums[dst] = nums[dst], nums[src]
            else:
                done = True
