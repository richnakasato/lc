/*
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (38.03%)
 * Total Accepted:    183K
 * Total Submissions: 481.2K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 *
 * Return the following binary tree:
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* helper(const vector<int>& pre, int ps, int pe,
                     const vector<int>& ino, int is, int ie)
    {
        if (ps == pe) return nullptr;
        TreeNode* root = new TreeNode(pre[ps]);
        int num_left = 0;
        int trav = is;
        while (ino[trav] != pre[ps]) {
            ++num_left;
            ++trav;
        }
        root->left = helper(pre, ps+1, ps+1+num_left,
                            ino, is, is+num_left);
        root->right = helper(pre, ps+1+num_left, pe,
                             ino, is+1+num_left, ie);
        return root;
    }
public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder)
    {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
