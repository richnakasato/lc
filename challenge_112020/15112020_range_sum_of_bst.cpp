/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* curr, int lo, int hi, int& sum) {
        if (!curr) return;
        if (lo <= curr->val && curr->val <= hi) {
            sum += curr->val;
            dfs(curr->left, lo, hi, sum);
            dfs(curr->right, lo, hi, sum);
        } else if (curr->val < lo) dfs(curr->right, lo, hi, sum);
        else dfs(curr->left, lo, hi, sum);
        return;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;
        auto sum = 0;
        dfs(root, low, high, sum);
        return sum;
    }
};
