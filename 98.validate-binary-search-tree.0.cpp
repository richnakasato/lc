/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.79%)
 * Total Accepted:    321.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
 *
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
#include <limits>
#include <queue>
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool done = false;
        long min = std::numeric_limits<long>::min();
        long max = std::numeric_limits<long>::max();
        TreeNode* curr = root;
        std::queue<std::tuple<long, TreeNode*, long>> bfs;
        while (!done) {
            if (curr) {
                bfs.push(std::make_tuple(min, curr, max));
                max = curr->val;
                curr = curr->left;
            }
            else {
                if (bfs.size()) {
                    auto temp = bfs.front();
                    bfs.pop();
                    min = std::get<0>(temp);
                    curr = std::get<1>(temp);
                    max = std::get<2>(temp);
                    // process...
                    if (curr->val <= min || curr->val >= max) {
                        return false;
                    }
                    min = curr->val;
                    curr = curr->right;
                }
                else {
                    done = true;
                }
            }
        }
        return true;
    }
};
