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
    ListNode* middleNode(ListNode* head) {
        if (!head) return head;
        int count = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next && slow->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return fast->next ? slow->next : slow;
    }
};
