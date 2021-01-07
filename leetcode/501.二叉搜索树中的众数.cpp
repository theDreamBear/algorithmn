/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    map<int, int> h;
    void inorderTraversal(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        inorderTraversal(root->left);
        ++h[root->val];
        inorderTraversal(root->right);
    }

    /*
        二叉搜索树中序遍历
    */
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        inorderTraversal(root);
        int maxTimes = 0;
        for (auto& kv : h) {
            if (kv.second > maxTimes) {
                maxTimes = kv.second;
            }
        }

        for (auto& kv : h) {
            if (kv.second == maxTimes) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }
};
// @lc code=end

