/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    pair<TreeNode *, TreeNode *> next(TreeNode *node) {
        TreeNode *fa = node->right;
        TreeNode *cur = node->right->left;
        while (cur->left) {
            fa = cur;
            cur = cur->left;
        }
        return {fa, cur};
    }

    pair<TreeNode*, TreeNode*> findNodeWithFather(TreeNode* root, int key) {
        TreeNode* fa = nullptr;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val == key) {
                break;
            }
            fa = cur;
            if (cur->val > key) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (!cur) {
            return {nullptr, nullptr};
        }
        return {fa, cur};
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        auto [fa, cur] = findNodeWithFather(root, key);
        if (!cur) {
            return root;
        }
        TreeNode* TreeNode::*child = nullptr;
        if (fa) {
            if (fa->right == cur) {
                child = &TreeNode::right;
            } else {
                child = &TreeNode::left;
            }
        }
        if (!cur->right) {
            cur = cur->left;
            if (child) {
                fa->*child = cur;
            }
        } else if (!cur->right->left) {
            cur->right->left = cur->left;
            cur = cur->right;
            if (child) {
                fa->*child = cur;
            }
        } else {
            auto[pre, node] = next(cur);
            pre->left = node->right;
            node->right = cur->right;
            node->left = cur->left;
            if (child) {
                fa->*child = node;
            } else {
                cur = node;
            }
        }
        if (child) {
            return root;
        }
        return cur;
    }
};
// @lc code=end

