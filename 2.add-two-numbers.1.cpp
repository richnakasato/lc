/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.74%)
 * Total Accepted:    673.4K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* lhs = l1;
        ListNode* rhs = l2;
        ListNode dummy = ListNode(0);
        ListNode* merge = &dummy;
        int carry = 0;
        while (lhs && rhs) {
            int sum = carry + lhs->val + rhs->val;
            carry = sum / 10;
            merge->next = new ListNode(sum % 10);
            lhs = lhs->next;
            rhs = rhs->next;
            merge = merge->next;
        }
        while (lhs) {
            int sum = carry + lhs->val;
            carry = sum / 10;
            merge->next = new ListNode(sum % 10);
            lhs = lhs->next;
            merge = merge->next;
        }
        while (rhs) {
            int sum = carry + rhs->val;
            carry = sum / 10;
            merge->next = new ListNode(sum % 10);
            rhs = rhs->next;
            merge = merge->next;
        }
        if (carry) {
            merge->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
