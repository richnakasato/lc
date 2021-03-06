/*
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (47.86%)
 * Total Accepted:    218.8K
 * Total Submissions: 457K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 *
 * Example:
 *
 *
 * Given the sorted array: [-10,-3,0,5,9],
 *
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 *
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* helper(const std::vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + ((hi - lo)/2);
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = helper(nums, lo, mid - 1);
        curr->right = helper(nums, mid + 1, hi);
        return curr;
    }
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        if (!nums.size()) return nullptr;
        return helper(nums, 0, nums.size() - 1);
    }
};
