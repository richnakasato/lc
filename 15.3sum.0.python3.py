#
# [15] 3Sum
#
# https://leetcode.com/problems/3sum/description/
#
# algorithms
# Medium (22.52%)
# Total Accepted:    430.4K
# Total Submissions: 1.9M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# Given an array nums of n integers, are there elements a, b, c in nums such
# that a + b + c = 0? Find all unique triplets in the array which gives the sum
# of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
#
#
#
class Solution:
    def twoSum(self, nums, target):
        results = list()
        l = 0
        r = len(nums)-1
        while l < r:
            sum_ = nums[l] + nums[r]
            if sum_ < target:
                l+=1
            elif sum_ > target:
                r-=1
            else:
                results.append([nums[l], nums[r]])
                l+=1
        return results

    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        three_sums = set()
        for idx,num in enumerate(nums[:-2]):
            sub_target = 0 - num
            two_sums = self.twoSum(nums[idx+1:], sub_target)
            for two_sum in two_sums:
                temp = tuple([num] + two_sum[:])
                three_sums.add(temp)
        three_sums = [list(x) for x in three_sums]
        return three_sums

