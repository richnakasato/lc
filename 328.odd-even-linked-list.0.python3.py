#
# [328] Odd Even Linked List
#
# https://leetcode.com/problems/odd-even-linked-list/description/
#
# algorithms
# Medium (47.18%)
# Total Accepted:    122.3K
# Total Submissions: 259.3K
# Testcase Example:  '[1,2,3,4,5]'
#
# Given a singly linked list, group all odd nodes together followed by the even
# nodes. Please note here we are talking about the node number and not the
# value in the nodes.
#
# You should try to do it in place. The program should run in O(1) space
# complexity and O(nodes) time complexity.
#
# Example 1:
#
#
# Input: 1->2->3->4->5->NULL
# Output: 1->3->5->2->4->NULL
#
#
# Example 2:
#
#
# Input: 2->1->3->5->6->4->7->NULL
# Output: 2->3->6->7->1->5->4->NULL
#
#
# Note:
#
#
# The relative order inside both the even and odd groups should remain as it
# was in the input.
# The first node is considered odd, the second node even and so on ...
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from collections import deque

class Solution:
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        Time: O(nodes)
        Space: O(nodes)
        """
        if not head or not head.next:
            return head
        else:
            odds = deque()
            evens = deque()
            curr = head
            count = 0
            while curr:
                if not count%2:
                    odds.append(curr.val)
                else:
                    evens.append(curr.val)
                curr = curr.next
                count += 1
            curr = head
            while curr:
                if odds:
                    temp = odds.popleft()
                else:
                    temp = evens.popleft()
                curr.val = temp
                curr = curr.next
            return head

