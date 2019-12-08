/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (45.77%)
 * Total Accepted:    306.1K
 * Total Submissions: 668.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 *
 *
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 *
 * return its level order traversal as:
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
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
truct QueueNode {
    TreeNode* node;
    int level;
    QueueNode(TreeNode* n, int l) {
        node = n;
        level = l;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        std::queue<QueueNode> level_order;
        QueueNode temp(root, 0);
        level_order.push(temp);
        while (!level_order.empty()) {
            temp = level_order.front();
            level_order.pop();
            if (temp.level == result.size()) {
                result.push_back(std::vector<int>{});
            }
            result[temp.level].push_back(temp.node->val);
            if (temp.node->left) level_order.push(QueueNode(temp.node->left, temp.level+1));
            if (temp.node->right) level_order.push(QueueNode(temp.node->right, temp.level+1));
        }
        return result;
    }
};
