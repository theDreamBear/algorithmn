/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

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
    int maxPathSumHelper(TreeNode* root, int& maxValue, int current) {
        if (NULL == root) {
            return 0;
        }
        int left = maxPathSumHelper(root->left, maxValue, current);
        int right = maxPathSumHelper(root->right, maxValue, current);
        if (left > 0) {
            current += left;
        }
        if (right > 0) {
            current += right;
        }
        if (current > maxValue) {
            maxValue = current;
        }
    }

    int maxPathSum(TreeNode* root) {

    }
};
// @lc code=end

