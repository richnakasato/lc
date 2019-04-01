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
#include <algorithm>
#include <queue>
#include <tuple>

struct Compare {
    bool operator()(const std::tuple<int,ListNode*>& lhs,
                   const std::tuple<int,ListNode*>& rhs)
    {
        return std::get<1>(lhs)->val > std::get<1>(rhs)->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        std::vector<ListNode*> currs = lists;
        std::priority_queue<std::tuple<int,ListNode*>,
                            std::vector<std::tuple<int,ListNode*>>,
                            Compare> pq;
        for (size_t i=0; i<currs.size(); ++i) {
            if (currs[i]) {
                auto temp = std::make_tuple(i,currs[i]);
                pq.push(temp);
                currs[i] = currs[i]->next;
            }
        }
        ListNode dummy = {0};
        ListNode* curr = &dummy;
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int i = std::get<0>(temp);
            ListNode* node = std::get<1>(temp);
            curr->next = node;
            curr = curr->next;
            if (currs[i]) {
                temp = std::make_tuple(i,currs[i]);
                pq.push(temp);
                currs[i] = currs[i]->next;
            }
        }
        return dummy.next;
    }
};
