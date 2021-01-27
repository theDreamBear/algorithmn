/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* l = NULL, *r = NULL;
    void leftLimit(TreeNode* node, int low, bool& ok) {
        if (ok || node == NULL) {
            return;
        }
        leftLimit(node->left, low, ok);
        if (node->val >= low) {
            node->left = NULL;
            if (l) {
                r = node;
                r->left = l;
                l = NULL;
                r = NULL;
                ok = true;
                return;
            }
            l = node;
        }
        leftLimit(node->right, low, ok);
    }

    void rightLimit(TreeNode* node, int high, bool& ok) {
        if (ok || node == NULL) {
            return;
        }
        rightLimit(node->left, high, ok);
        if (node->val <= high) {
            if (l) {
                r = l;
                l = node;
            } else {
                l = node;
            }
        } else {
            r->right = l;
            l = NULL;
            r = NULL;
            ok = true;
        }
        rightLimit(node->right, high, ok);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 如果根 在low ,high 之间 则 在左右分别找
        // 若根 < low , 则在右边找
        // 若根 > high, 则在左边找
        // 左子树第一个大于等于 low 的作为作为左节点
        // 右子树最后一个小于 high 的节点作为右或者根
        if (root == NULL) {
            return NULL;
        }
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        // 左边界
        bool bl = false;
        leftLimit(root, low, bl);
        // 右边界
        //bool br = false;
        //rightLimit(root, high, br);
        return root;
    }
};
// @lc code=end

