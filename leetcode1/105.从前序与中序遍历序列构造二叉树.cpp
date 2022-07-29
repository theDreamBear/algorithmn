/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTreeHelper(vector<int>& preorder, int l1, int h1, vector<int>& inorder, int l2, int h2) {
        if (l1 > h1) {
            return nullptr;
        }
        int val = preorder[l1];
        int i = l2;
        for (; i <= h2; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        int lsz = i - l2;
        auto root = new TreeNode(val);
        root->left = buildTreeHelper(preorder, l1 + 1, l1 + lsz, inorder, l2, i - 1);
        root->right= buildTreeHelper(preorder, l1 + lsz + 1, h1, inorder, i + 1, h2);
        return root;
    }

    // 最一般的递归构造
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

