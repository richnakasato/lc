/*
plan: dfs, track counts from left or right children into parent, if found sum,
      add to result (not sure if should track actual paths or just counts)...
      also, need to track all sums somehow... since sums can come from multiple
      places... map? maybe should pass parent value downwards instead? include
      parent value or not include parent value... perhaps in list? eats a lot
      of memory... map might be better so we can just look for nums we need
time: linear wrt nodes
space: ???
*/

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
    void helper(TreeNode* curr, int sum, vector<int> sums, int& result) {
        if (!curr) return;
        if (curr->val == sum) ++result;
        auto next_sums = vector<int>{};
        next_sums.push_back(curr->val);
        auto target = sum - curr->val;
        for (auto s : sums) {
            auto curr_sum = curr->val + s;
            if (curr_sum == sum) ++result;
            next_sums.push_back(curr_sum);
        }
        if (curr->left) helper(curr->left, sum, next_sums, result);
        if (curr->right) helper(curr->right, sum, next_sums, result);
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        auto result = 0;
        auto sums = vector<int>{};
        helper(root, sum, sums, result);
        return result;
    }
};
