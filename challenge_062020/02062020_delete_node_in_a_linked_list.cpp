/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Plan: Delete node by just copying over current node.
// Time: O(1)
// Space: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) return;
        auto temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
        return;
    }
};
