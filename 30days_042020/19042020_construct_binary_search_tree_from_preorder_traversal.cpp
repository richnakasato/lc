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
    /*
    TreeNode* helper(vector<int>& preorder, vector<int>::iterator start, vector<int>::iterator end) {
        if (start > end) return NULL;
        auto root = new TreeNode(preorder[start]);
        auto it = find_if(start,  end,  [&root](const auto& v){return root->val < v ? true : false;});
        if (it == end) return root;
        auto lhs = helper(preorder, start + 1, split - 1);
        auto rhs = helper(preorder, split, end);
        root->left = lhs;
        root->right = rhs;
        return root;
    }
    */
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end) return NULL;
        auto root = new TreeNode(preorder[start]);
        auto split = start + 1;
        while (split <= end && preorder[split] < root->val) ++split;
        auto lhs = helper(preorder, start + 1, split - 1);
        auto rhs = helper(preorder, split, end);
        root->left = lhs;
        root->right = rhs;
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return NULL;
        return helper(preorder, 0, preorder.size() - 1);
        //return helper(preorder, begin(preorder), end(preorder));
    }
};
