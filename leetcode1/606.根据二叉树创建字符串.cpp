/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    string tree2strHelper(TreeNode* root) {
        if (nullptr == root) {
            return "";
        }
        if (nullptr == root->left && nullptr == root->right) {
            return to_string(root->val);
        }
        string ans = to_string(root->val);
        string left = "";
        string right = "";
        if (root->left) {
            left = tree2strHelper(root->left);
        }
        if (root->right) {
            right = tree2strHelper(root->right);
        }
        ans += "(" + left + ")";
        if (right.empty()) {
            return ans;
        }
        return ans + "(" + right + ")";
    }

    string tree2str(TreeNode* root) {
        if (nullptr == root) {
            return "";
        }
        return tree2strHelper(root);
    }
};
// @lc code=end

