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
    struct DiaLeg {
        int max_dia;
        int max_leg;
    };

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        DiaLeg lhs = helper(root->left);
        DiaLeg rhs = helper(root->right);
        return getMax(lhs, rhs);
    }

    DiaLeg helper(TreeNode* root) {
        DiaLeg result;
        if (!root) return result;
        DiaLeg lhs = helper(root->left);
        DiaLeg rhs = helper(root->right);
        int cur_dia = getCurDia(lhs, rhs);
        int max_dia = getMaxDia(lhs, rhs);
        result.max_dia = std::max(cur_dia, max_dia);
        result.max_leg = getMaxLeg(lhs, rhs);
        return result;
    }

    int getMax(DiaLeg lhs, DiaLeg rhs) {
        return std::max(getCurDia(lhs, rhs), getMaxDia(lhs, rhs));
    }

    int getMaxDia(DiaLeg lhs, DiaLeg rhs) {
        return std::max(lhs.max_dia, rhs.max_dia);
    }

    int getCurDia(DiaLeg lhs, DiaLeg rhs) {
        return lhs.max_leg + rhs.max_leg;
    }

    int getMaxLeg(DiaLeg lhs, DiaLeg rhs) {
        return 1 + std::max(lhs.max_leg, rhs.max_leg);
    }
};
