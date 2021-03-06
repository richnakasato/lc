/*
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (36.82%)
 * Total Accepted:    131.7K
 * Total Submissions: 357.6K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 *
 * Note:
 * You may assume that duplicates do not exist in the tree.
 *
 * For example, given
 *
 *
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode* helper(const std::vector<int>& in, int is, int ie,
                     const std::vector<int>& po, int ps, int pe)
    {
        if (is == ie) return NULL;
        int root_val = po[pe-1];
        int root_idx = is;
        while (in[root_idx] != root_val) ++root_idx;
        int delta = root_idx - is;
        TreeNode* root = new TreeNode(root_val);
        root->left = helper(in, is, is+delta, po, ps, ps+delta);
        root->right = helper(in, is+delta+1, ie, po, ps+delta, pe-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
