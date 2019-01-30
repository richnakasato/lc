/*
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (48.56%)
 * Total Accepted:    183.4K
 * Total Submissions: 377.7K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given a binary search tree, write a function kthSmallest to find the kth
 * smallest element in it.
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * ⁠  3
 * ⁠ / \
 * ⁠1   4
 * ⁠ \
 * 2
 * Output: 1
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * ⁠      5
 * ⁠     / \
 * ⁠    3   6
 * ⁠   / \
 * ⁠  2   4
 * ⁠ /
 * ⁠1
 * Output: 3
 *
 *
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to
 * find the kth smallest frequently? How would you optimize the kthSmallest
 * routine?
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
#include <vector>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        std::vector<int> results;
        std::stack<TreeNode*> in_order;
        TreeNode* curr = root;
        bool done = false;
        while (!done) {
            if (curr) {
                in_order.push(curr);
                curr = curr->left;
            }
            else {
                if (!in_order.empty()) {
                    curr = in_order.top();
                    in_order.pop();
                    results.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    done = true;
                }
            }
        }
        return results[k-1];
    }
};
