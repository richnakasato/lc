/*
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (24.79%)
 * Total Accepted:    321.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * Output: false
 * Explanation: The input is: [5,1,4,null,null,3,6]. The root node's
 * value
 * is 5 but its right child's value is 4.
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
#include <limits>
#include <queue>
#include <stack>
class Solution {
    bool check_bounds(long min, int val, long max) {
        return min < val && val < max;
    }
    bool isValidBST_helper(long min, TreeNode* curr, long max) {
        if (!curr) return true;
        if (!check_bounds(min, curr->val, max)) return false;
        return isValidBST_helper(min, curr->left, curr->val) &&
               isValidBST_helper(curr->val, curr->right, max);
    }
    bool isValidBST_rec(TreeNode* root) {
        long min = std::numeric_limits<long>::min();
        long max = std::numeric_limits<long>::max();
        return isValidBST_helper(min, root, max);
    }
    bool isValidBST_bfs(TreeNode* root) {
        long min = std::numeric_limits<long>::min();
        long max = std::numeric_limits<long>::max();
        TreeNode* curr = root;
        std::queue<std::tuple<long, TreeNode*, long>> bfs;
        bfs.push(std::make_tuple(min, curr, max));
        while (bfs.size()) {
            auto temp = bfs.front();
            bfs.pop();
            min = std::get<0>(temp);
            curr = std::get<1>(temp);
            max = std::get<2>(temp);
            if (curr) {
                if (!check_bounds(min, curr->val, max)) return false;
                bfs.push(std::make_tuple(min, curr->left, curr->val));
                bfs.push(std::make_tuple(curr->val, curr->right, max));
            }
        }
        return true;
    }
    bool isValidBST_dfs(TreeNode* root) {
        bool done = false;
        long min = std::numeric_limits<long>::min();
        long max = std::numeric_limits<long>::max();
        TreeNode* curr = root;
        std::stack<std::tuple<long, TreeNode*, long>> dfs;
        while (!done) {
            if (curr) {
                dfs.push(std::make_tuple(min, curr, max));
                max = curr->val;
                curr = curr->left;
            }
            else {
                if (dfs.size()) {
                    auto temp = dfs.top();
                    dfs.pop();
                    min = std::get<0>(temp);
                    curr = std::get<1>(temp);
                    max = std::get<2>(temp);
                    if (!check_bounds(min, curr->val, max)) return false;
                    min = curr->val;
                    curr = curr->right;
                }
                else {
                    done = true;
                }
            }
        }
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        //return isValidBST_rec(root);
        //return isValidBST_bfs(root);
        return isValidBST_dfs(root);
    }
};
