/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth1(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        return max(maxDepth1(root->left), maxDepth1(root->right)) + 1;
    }

    int dfs(TreeNode* node, int depth) {
        if (nullptr == node) {
            return depth;
        }
        int left = dfs(node->left, depth + 1);
        int right = dfs(node->right, depth + 1);
        return max(left, right);
    }

    int maxDepth(TreeNode* root) {
       return dfs(root, 0);
    }
};
// @lc code=end

