/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (41.95%)
 * Total Accepted:    324.7K
 * Total Submissions: 774.1K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 *
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 *
 *
 *
 * But the following [1,2,2,null,3,null,3]  is not:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool helper(TreeNode* p, TreeNode* q)
    {
        if (!p && !q) return true;
        if (!p && q) return false;
        if (p && !q) return false;
        bool value_compare = p->val == q->val;
        bool left_compare = helper(p->left, q->right);
        bool right_compare = helper(p->right, q->left);
        return value_compare && left_compare && right_compare;
    }

    bool isSymmetric(TreeNode* root)
    {
        if (!root) return true;
        else return helper(root->left, root->right);
    }
};
