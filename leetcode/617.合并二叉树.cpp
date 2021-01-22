/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
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
    // 先序遍历
    void mergeTreesHelper(TreeNode *t1, TreeNode *t2, TreeNode *&root,
                          int pos) {
        if (t1 == NULL && t2 == NULL) {
            return;
        }
        if (t1 == NULL) {
            TreeNode *node = new TreeNode(t2->val);
            if (root == NULL) {
                root = node;
            } else {
                if (pos == 0) {
                    root->left = node;
                } else {
                    root->right = node;
                }
            }
            mergeTreesHelper(NULL, t2->left, node, 0);
            mergeTreesHelper(NULL, t2->right, node, 1);
            return;
        }
        if (t2 == NULL) {
            TreeNode *node = new TreeNode(t1->val);
            if (root == NULL) {
                root = node;
            } else {
                if (pos == 0) {
                    root->left = node;
                } else {
                    root->right = node;
                }
            }
            mergeTreesHelper(NULL, t1->left, node, 0);
            mergeTreesHelper(NULL, t1->right, node, 1);
            return;
        }
        TreeNode *node = new TreeNode(t2->val + t1->val);
        if (root == NULL) {
            root = node;
        } else {
            if (pos == 0) {
                root->left = node;
            } else {
                root->right = node;
            }
        }
        mergeTreesHelper(t1->left, t2->left, node, 0);
        mergeTreesHelper(t1->right, t2->right, node, 1);
    }

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        TreeNode* root = NULL;
        mergeTreesHelper(t1, t2, root, 0);
        return root;
    }
};
// @lc code=end
