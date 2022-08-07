/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }
        int left = maxPathSum(root->left, ans);
        int right = maxPathSum(root->right, ans);
        int temp = root->val;
        temp = max(temp + left, temp);
        temp = max(temp + right, temp);
        ans = max(ans, temp);
        int mb = max(0, max(left, right));
        return mb + root->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = -10000;
        maxPathSum(root, ans);
        return ans;
    }
};
// @lc code=end

