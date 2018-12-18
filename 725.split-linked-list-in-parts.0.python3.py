#
# [725] Split Linked List in Parts
#
# https://leetcode.com/problems/split-linked-list-in-parts/description/
#
# algorithms
# Medium (47.83%)
# Total Accepted:    20.2K
# Total Submissions: 42.2K
# Testcase Example:  '[1,2,3,4]\n5'
#
# Given a (singly) linked list with head node root, write a function to split
# the linked list into k consecutive linked list "parts".
#
# The length of each part should be as equal as possible: no two parts should
# have a size differing by more than 1.  This may lead to some parts being
# null.
#
# The parts should be in order of occurrence in the input list, and parts
# occurring earlier should always have a size greater than or equal parts
# occurring later.
#
# Return a List of ListNode's representing the linked list parts that are
# formed.
#
#
# Examples
# 1->2->3->4, k = 5 // 5 equal parts
# [ [1],
# [2],
# [3],
# [4],
# null ]
#
# Example 1:
#
# Input:
# root = [1, 2, 3], k = 5
# Output: [[1],[2],[3],[],[]]
# Explanation:
# The input and each element of the output are ListNodes, not arrays.
# For example, the input root has root.val = 1, root.next.val = 2,
# \root.next.next.val = 3, and root.next.next.next = null.
# The first element output[0] has output[0].val = 1, output[0].next = null.
# The last element output[4] is null, but it's string representation as a
# ListNode is [].
#
#
#
# Example 2:
#
# Input:
# root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
# Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most
# 1, and earlier parts are a larger size than the later parts.
#
#
#
# Note:
# The length of root will be in the range [0, 1000].
# Each value of a node in the input will be an integer in the range [0, 999].
# k will be an integer in the range [1, 50].
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def list_len(self, root):
        result = 0
        if root:
            curr = root
            while curr:
                result += 1
                curr = curr.next
        return result

    def length_builder(self, root, k):
        list_len = self.list_len(root)
        part_len = list_len//k
        part_rem = list_len%k
        lengths = [part_len for _ in range(k)]
        length_idx = 0
        while part_rem:
            lengths[length_idx] += 1
            length_idx += 1
            part_rem -= 1
        return list_len, lengths

    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        result = [None for _ in range(k)]
        total_length, part_lengths = self.length_builder(root, k)
        if total_length:
            prev = None
            curr = root
            part_idx = 0
            curr_count = 0
            while curr:
                if curr_count < part_lengths[part_idx]:
                    if curr_count == 0:
                        result[part_idx] = curr
                        if prev:
                            prev.next = None
                    prev = curr
                    curr = curr.next
                    curr_count += 1
                else:
                    curr_count = 0
                    part_idx += 1
        return result

