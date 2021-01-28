/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
    void trimBSTHelper(TreeNode* node, int low, int high) {
        if (node == NULL) {
            return;
        }
        // left
        TreeNode* cur = node;
        while (cur && cur->left) {
            if (cur->left->val >= low) {
                cur = cur->left;
            } else {
                cur->left = cur->left->right;
            }
        }
        // right
        cur = node;
        while (cur && cur->right) {
            if (cur->right->val <= high) {
                cur = cur->right;
            } else {
                cur->right = cur->right->left;
            }
        }
    }

    /*
        不要看到二叉搜索树就中序遍历
    */
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 如果根 在low ,high 之间 则 在左右分别找
        // 若根 < low , 则在右边找
        // 若根 > high, 则在左边找
        if (root == NULL) {
            return NULL;
        }
        // 1. 找到头结点
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        // 2. 剪枝
        //trimBSTHelper(root, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
// @lc code=end
