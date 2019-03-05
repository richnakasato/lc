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
        std::vector<ListNode*> currs;
        for (size_t i=0; i<lists.size(); ++i) {
            currs.push_back(lists[i]);
        }
        ListNode dummy = ListNode(std::numeric_limits<int>::max());
        ListNode* merged = &dummy;
        ListNode* min = NULL;
        int idx;
        int count = 0;
        while (min != &dummy) {
            min = &dummy;
            idx = 0;
            for (size_t i=0; i<currs.size(); ++i) {
                if (currs[i]) {
                    min = min_node(min, currs[i]);
                    idx = min == currs[i] ? i : idx;
                }
            }
            if (min != &dummy) {
                currs[idx] = currs[idx]->next;
                merged->next = min;
                merged = merged->next;
            }
        }
        return dummy.next;
    }
private:
    ListNode* min_node(ListNode* lhs, ListNode* rhs) {
        if (!rhs) return lhs;
        if (!lhs) return rhs;
        if (lhs->val < rhs->val) return lhs;
        else return rhs;
    }
};

