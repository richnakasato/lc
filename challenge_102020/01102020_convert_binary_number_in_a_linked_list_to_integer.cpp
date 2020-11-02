/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        auto result = 0;
        if (!head) return result;
        auto count = 0;
        auto ptr = head;
        while (ptr) {
            /* faster version on has 1 loop:
            result <<= 1;
            result |= ptr->val;
            */
            ++count;
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            result += ptr->val * pow(2, --count);
            ptr = ptr->next;
        }
        return result;
    }
};
