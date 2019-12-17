/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (31.53%)
 * Total Accepted:    303.9K
 * Total Submissions: 963.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    struct compare {
        bool operator()(ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return NULL;
        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> pq;
        for (int i=0; i<n; ++i) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if (temp && temp->next) {
                pq.push(temp->next);
            }
            curr->next = temp;
            curr = curr->next;
        }
        return dummy.next;
    }
};
