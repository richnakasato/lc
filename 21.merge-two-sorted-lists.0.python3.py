#
# [21] Merge Two Sorted Lists
#
# https://leetcode.com/problems/merge-two-sorted-lists/description/
#
# algorithms
# Easy (44.34%)
# Total Accepted:    454.8K
# Total Submissions: 1M
# Testcase Example:  '[1,2,4]\n[1,3,4]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
#
# Example:
#
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = merged = ListNode(None)
        left = l1
        right = l2
        while left and right:
            if left.val < right.val:
                merged.next = left
                left = left.next
            else:
                merged.next = right
                right = right.next
            merged = merged.next
        while left:
            merged.next = left
            left = left.next
            merged = merged.next
        while right:
            merged.next = right
            right = right.next
            merged = merged.next
        return dummy.next

