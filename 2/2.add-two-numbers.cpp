/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (28.21%)
 * Total Accepted:    410.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* head = nullptr;
      ListNode* curr = nullptr;
      ListNode* t1 = l1;
      ListNode* t2 = l2;
      int v1, v2, v3;
      bool c = false;
      while(!(t1==nullptr && t2==nullptr)) {
        v1 = extractVal(t1);
        v2 = extractVal(t2);
        v3 = v1 + v2;
        if(c) {
          v3++;
          c = false;
        }
        if(v3 > 9) {
          v3 = v3 % 10;
          c = true;
        }
        ListNode* lnode = new ListNode(v3);
        if(head == nullptr) {
          head = lnode;
          curr = head;
        }
        else {
          curr->next = lnode; // append new node onto our list
          curr = lnode; // set current pointer to new node
        }
        if(t1!=nullptr) {
          t1 = t1->next;
        }
        if(t2!=nullptr) {
          t2 = t2->next;
        }
      }
      // remember to append 1 if we have a remaining carry bit
      if(c) {
        ListNode* lnode = new ListNode(1);
        curr->next = lnode;
      }
      return head;
    }

private:
    int extractVal(ListNode* node) {
      return (node == nullptr) ? 0 : node->val;
    }
};
