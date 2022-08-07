/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    pair<int, int> robHelper(TreeNode* node) {
        if (!node) {
            // 包含的最大值， 不包含的最大值
            return {0, 0};
        }
        auto pl = robHelper(node->left);
        auto pr = robHelper(node->right);

        int ne = pl.second + pr.second + node->val;
        int nn = max(pl.first, pl.second) + max(pr.first, pr.second);
        return {ne, nn};
    }

    int rob(TreeNode* root) {
        auto p = robHelper(root);
        return max(p.first, p.second);
    }
};
// @lc code=end

