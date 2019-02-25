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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.empty()) return NULL;
        return helper(preorder, 0, preorder.size(),
                      inorder, 0, inorder.size());
    }
private:
    TreeNode* helper(std::vector<int>& preorder, int p_start, int p_end,
                     std::vector<int>& inorder, int i_start, int i_end)
    {
        if (p_start == p_end) return NULL;
        int root_val = preorder[p_start];
        TreeNode* root = new TreeNode(root_val);
        int count = 0;
        while (inorder[i_start+count] != root_val)
            ++count;
        root->left = helper(preorder, p_start+1, p_start+1+count,
                            inorder, i_start, i_start+count);
        root->right = helper(preorder, p_start+1+count, p_end,
                             inorder, i_start+1+count, i_end);
        return root;
    }
};
