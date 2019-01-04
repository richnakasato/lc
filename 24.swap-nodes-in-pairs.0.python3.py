# [24] Swap Nodes in Pairs
#
# https://leetcode.com/problems/swap-nodes-in-pairs/description/
#
# algorithms
# Medium (41.86%)
# Total Accepted:    258.5K
# Total Submissions: 617.4K
# Testcase Example:  '[1,2,3,4]'
#
# Given a linked list, swap every two adjacent nodes and return its head.
#
# Example:
#
#
# Given 1->2->3->4, you should return the list as 2->1->4->3.
#
# Note:
#
#
# Your algorithm should use only constant extra space.
# You may not modify the values in the list's nodes, only nodes itself may be
# changed.
#
#
#
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head and head.next:
            dummy = ListNode(None)
            dummy.next = head
            a = dummy
            while a.next and a.next.next:
                b = a.next
                c = b.next
                d = c.next
                a.next = c
                c.next = b
                b.next = d
                a = b
            head = dummy.next
        return head

    def printList(self, head):
        curr = head
        while curr:
            print('{}->'.format(curr.val), end='')
            curr = curr.next
        print('None')


def main():
    node_a = ListNode(1)
    node_b = ListNode(2)
    node_c = ListNode(3)
    node_d = ListNode(4)
    head = node_a
    node_a.next = node_b
    node_b.next = node_c
    node_c.next = node_d
    solution = Solution()
    solution.printList(head)
    head = solution.swapPairs(head)
    solution.printList(head)


if __name__ == "__main__":
    main()

