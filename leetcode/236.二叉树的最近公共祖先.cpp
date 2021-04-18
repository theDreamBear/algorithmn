/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */
#include <ranges.h>
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
    
    TreeNode* findNode(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) {
            return nullptr;
        }
        TreeNode* left = findNode(node->left, p, q);
        TreeNode* right = findNode(node->right, p, q);
        // 后序遍历
        if (left && right) {
            return node;
        }
        if (left) {
            if (node->val == p->val || node->val == q->val) {
                return node;
            }
            return left;
        }
        if (right) {
            if (node->val == p->val || node->val == q->val) {
                return node;
            }
            return right;
        }
        if (node->val == p->val || node->val == q->val) {
            return node;
        }
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findNode(root, p, q);
    }

    /*
        存储父节点链
    */
    unordered_map<int, TreeNode*> father;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        if (node->left) {
            father[node->left->val] = node;
            dfs(node->left);
        }
        if (node->right) {
            father[node->right->val] = node;
            dfs(node->right);
        }
    }

    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root->val] = NULL;
        dfs(root);
        unordered_map<int, bool> visited;
        TreeNode* cur = p;
        while (cur) {
            visited[cur->val] = true;
            cur = father[cur->val];
        }
        cur = q;
        while (cur) {
            if (visited[cur->val]) {
                return cur;
            }
            cur = father[cur->val];
        }
        return nullptr;
    }
};
// @lc code=end
