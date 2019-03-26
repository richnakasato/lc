/*
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (33.68%)
 * Total Accepted:    221K
 * Total Submissions: 656.2K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 *
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 *
 * ⁠       _______3______
 * ⁠      /              \
 * ⁠   ___5__          ___1__
 * ⁠  /      \        /      \
 * ⁠  6      _2       0       8
 * ⁠        /  \
 * ⁠        7   4
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself
 * ⁠            according to the LCA definition.
 *
 * Note:
 *
 *
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        std::unordered_map<TreeNode*,TreeNode*> parents;
        std::queue<std::tuple<TreeNode*,TreeNode*>> level_order;
        level_order.push(std::make_tuple(root, nullptr));
        while (level_order.size()) {
            auto temp = level_order.front();
            level_order.pop();
            TreeNode* child = std::get<0>(temp);
            TreeNode* parent = std::get<1>(temp);
            parents[child] = parent;
            if (child->left) level_order.push(std::make_tuple(child->left, child));
            if (child->right) level_order.push(std::make_tuple(child->right, child));
        }
        TreeNode* trav = p;
        std::vector<TreeNode*> lineage_p;
        while (trav) {
            lineage_p.push_back(trav);
            trav = parents[trav];
        }
        trav = q;
        std::vector<TreeNode*> lineage_q;
        while (trav) {
            lineage_q.push_back(trav);
            trav = parents[trav];
        }
        std::vector<TreeNode*>::reverse_iterator rit_p = lineage_p.rbegin();
        std::vector<TreeNode*>::reverse_iterator rit_q = lineage_q.rbegin();
        TreeNode* last_parent = nullptr;
        while (rit_p != lineage_p.rend() && rit_q != lineage_q.rend()) {
            if (*rit_p == *rit_q) last_parent = *rit_p;
            else break;
            ++rit_p;
            ++rit_q;
        }
        return last_parent;
    }
};
