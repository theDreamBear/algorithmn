/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
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
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (nullptr == left && nullptr == right) {
            return true;
        }
        if (nullptr == left || nullptr == right || left->val != right->val) {
            return false;
        }
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }

    // 1 前序遍历   ----  逆先序
    // 2 中序      ----   逆中序
    // 3 后序      ----   逆后序
    // 4 层次遍历
    // 注意: 针对空节点都要特殊处理
    // 什么叫逆呢， 比如 前序遍历是 当前-左-右， 逆先序就是 当前-右-左
};
// @lc code=end

