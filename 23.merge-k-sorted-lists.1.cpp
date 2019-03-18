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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct Compare {
        bool operator()(const ListNode* lhs, const ListNode* rhs)
        {
           return lhs->val > rhs->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> min_heap;
        for (size_t i=0; i<lists.size(); ++i) {
            if (lists[i])
                min_heap.push(lists[i]);
        }
        ListNode dummy = ListNode(0);
        ListNode* curr = &dummy;
        while (!min_heap.empty()) {
            ListNode* temp = min_heap.top();
            min_heap.pop();
            curr->next = temp;
            curr = curr->next;
            if (temp->next) {
                min_heap.push(temp->next);
            }
        }
        return dummy.next;
    }
};
