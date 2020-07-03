// Plan: BFS with queue. Put onto stack (vector) and when finished, pop off stack onto result.
// Time: Linear with nodes (traverse tree, pop stack into result)
// Space: Linear with nodes

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto result = vector<vector<int>>{};
        if (!root) return result;
        auto q = queue<tuple<TreeNode*,int>>{};
        q.push(tuple<TreeNode*,int>{root,0});
        while (!q.empty()) {
            auto item = q.front(); q.pop();
            auto node = get<0>(item);
            auto level = get<1>(item);
            if (size(result) == level) result.push_back(vector<int>{});
            result[level].push_back(node->val);
            if (node->left) q.push(tuple<TreeNode*,int>{node->left,level+1});
            if (node->right) q.push(tuple<TreeNode*,int>{node->right,level+1});
        }
        int lhs = 0;
        int rhs = size(result) - 1;
        while (lhs < rhs) {
            swap(result[lhs], result[rhs]);
            ++lhs;
            --rhs;
        }
        return result;
    }
};
