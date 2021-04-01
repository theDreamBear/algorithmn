/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
        dfs + memo
        记忆化方式可以改为
        vetor<vector<TreeNode*>> hash;
        hash.resize(n + 1, vector<TreeNode*>(n + 1));
    */
    unordered_map<string, vector<TreeNode*>> hash;
    vector<TreeNode*> dfs(int low, int high) {
        if (low > high) {
            return {NULL};
        }
        if (low == high) {
            return {new TreeNode(low)};
        }
        string key = to_string(low) + "_" + to_string(high);
        if (hash.count(key) > 0) {
            return hash[key];
        }
        vector<TreeNode*> ans;
        for (int i = low; i <= high; ++i) {
            auto left = dfs(low, i - 1);
            auto right = dfs(i + 1, high);
            for (int m = 0; m < left.size(); ++m) {
                for (int n = 0; n < right.size(); ++n) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[m];
                    root->right = right[n];
                    ans.push_back(root);
                }
            }
        }
        hash[key] = ans;
        return ans;
    }

    vector<TreeNode *> generateTrees(int n) {
        return dfs(1, n);
    }
};
// @lc code=end
