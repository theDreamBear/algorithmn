/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTreeHelper(vector<int>& inorder, int l1, int h1, vector<int>& postorder, int l2, int h2) {
        if (l1 > h1) {
            return nullptr;
        }
        int val = postorder[h2];
        TreeNode* root = new TreeNode(val);
        int i = l1;
        for (; i <= h1; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        int lsz = i - l1;
        root->left = buildTreeHelper(inorder, l1, i - 1, postorder, l2, l2 + lsz - 1);
        root->right = buildTreeHelper(inorder, i + 1, h1, postorder, l2 + lsz, h2 - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
    }
};
// @lc code=end

