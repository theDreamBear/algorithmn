/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    /*
        解法 1 , 层次遍历最右节点
        解法 2, 深度优先前序遍遍历

    */
    struct Node {
        TreeNode *tail;
        Node() { tail = NULL; }
    };
    Node nodes[50];

    void dfs(TreeNode *root, int depth) {
        // 判断边界
        if (root == NULL) {
            return;
        }
        // 具体逻辑
        nodes[depth].tail = root;
        // 递归
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

    vector<int> rightSideView_dfs(TreeNode *root) {
        dfs(root, 0);
        vector<int> ans;
        for (int i = 0; i < 50; ++i) {
            if (nodes[i].tail != NULL) {
                ans.push_back(nodes[i].tail->val);
            } else {
                return ans;
            }
        }
        return ans;
    }

    /*
        中 右 左 遍历 若已有值则忽略
    */
    void dfs2(TreeNode* root, vector<int>& ans, int depth) {
        // 边界
        if(NULL == root) {
            return;
        }
        // 具体逻辑, 若不存在才添加
        if (depth >= ans.size()) {
            ans.push_back(root->val);
        }
        // 递归
        dfs2(root->right, ans, depth + 1);
        dfs2(root->left, ans, depth + 1);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        dfs2(root, ans, 0);
        return ans;
    }
};
// @lc code=end
