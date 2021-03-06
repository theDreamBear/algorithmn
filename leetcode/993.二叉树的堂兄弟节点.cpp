/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

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
    pair<int, TreeNode*> find(TreeNode* node, int v, int depth = 0) {
        if (node == NULL) {
            return {-1, NULL};
        }
        if (node->left && node->left->val == v) {
            return {depth + 1, node};
        }
        if (node->right && node->right->val == v) {
            return {depth + 1, node};
        }
        auto left = find(node->left, v, depth + 1);
        auto right = find(node->right, v, depth + 1);
        if (left.first != -1) {
            return left;
        }
        return right;
    }

    bool isCousins(TreeNode *root, int x, int y) {
        auto left = find(root, x);
        auto right = find(root, y);
        return left.first == right.first && left.second != right.second;
    }
};
// @lc code=end
