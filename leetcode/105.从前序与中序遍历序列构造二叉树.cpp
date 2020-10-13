/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include<iostream>
#include <vector>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
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
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int l1, int h1, int l2, int h2) {
        if (l1 > h1 || l2 > h2) {
            return NULL;
        }
        if (l1 == h1 && l2 == h2) {
            return new TreeNode(preorder[l1]);
        }
        int l = preorder[l1];
        int off = 0;
        for (int i = 0; i + l2 <= h2; ++i) {
            if (inorder[i + l2] == l) {
                off = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(l);
        root->left = buildHelper(preorder, inorder, l1 + 1, l1 + off, l2, l2 + off);
        root->right = buildHelper(preorder, inorder, l1 + off + 1, h1, l2 + off + 1, h2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return buildHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

