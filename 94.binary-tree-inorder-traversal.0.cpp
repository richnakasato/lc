/*
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (53.55%)
 * Total Accepted:    370.9K
 * Total Submissions: 692.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 *
 * Example:
 *
 *
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * Output: [1,3,2]
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;

        std::vector<TreeNode*> inorder;
        TreeNode* curr = root;
        bool done = false;
        while (!done) {
            if (curr) {
                inorder.push_back(curr);
                curr = curr->left;
            }
            else {
                if (!inorder.empty()) {
                    curr = inorder.back();
                    inorder.pop_back();
                    result.push_back(curr->val);
                    curr = curr->right;
                }
                else {
                    done = true;
                }
            }
        }
        return result;
    }
};
