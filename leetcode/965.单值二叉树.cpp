/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

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
    bool isUnivalTreeHelper(TreeNode* node, const int val) {
        if (node == NULL) {
            return true;
        }
        if (node->val != val) {
            return false;
        }
        if (!isUnivalTreeHelper(node->left, val) || !isUnivalTreeHelper(node->right, val)) {
            return false;
        }
        return true;
    }

    bool isUnivalTree(TreeNode *root) {
        return isUnivalTreeHelper(root, root->val);
    }
};
// @lc code=end
