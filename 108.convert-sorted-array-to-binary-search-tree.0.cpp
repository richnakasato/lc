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
#include <algorithm>

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int start_idx, int end_idx) {
        if (start_idx > end_idx) return NULL;
        std::vector<int>::size_type mid = start_idx + (end_idx - start_idx)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start_idx, mid-1);
        root->right = helper(nums, mid+1, end_idx);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
