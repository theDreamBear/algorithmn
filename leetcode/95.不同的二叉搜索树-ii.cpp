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
        vetor<vector<vector<TreeNode*>>> hash;
        hash.resize(n + 1, vector<vector<TreeNode*>>(n + 1));
    */
    unordered_map<string, vector<TreeNode *>> hash;
    vector<TreeNode *> dfs(int low, int high) {
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
        vector<TreeNode *> ans;
        for (int i = low; i <= high; ++i) {
            auto left = dfs(low, i - 1);
            auto right = dfs(i + 1, high);
            for (int m = 0; m < left.size(); ++m) {
                for (int n = 0; n < right.size(); ++n) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left[m];
                    root->right = right[n];
                    ans.push_back(root);
                }
            }
        }
        hash[key] = ans;
        return ans;
    }

    /*
        递归方法
    */
    vector<TreeNode *> generateTrees1(int n) { return dfs(1, n); }

    /*
        启发于递归方式，构造动态规划版本
        vector<vector<vector<TreeNode*>>> dp[i][j]
        状态:           dp[i][j]  i -> j 构成的二叉搜索树集合
        状态转移方程：    dp[i][j]  dp[i][k - 1] X dp[k + 1][j]
                        可以发现在求dp[i][j]前需要知道dp[i][k - 1]和 dp[k +
       1][j] 所以我们依次求step = 2, 3, 4, ... 最终得到结果 结果: dp[0][n - 1]
        初始化
        dp[i][i] = {i}
        dp[i][k] = {NULL} {i > k}
    */
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> dp(n, vector<vector<TreeNode *>>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = {new TreeNode(i + 1)};
        }
        /*
            注意循环顺序
        */
        vector<TreeNode *> temp = {NULL};
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                for (int k = j; k <= j + i; ++k) {
                    vector<TreeNode *> *left, *right;
                    if (k == j) {
                        left = &temp;
                        right = &dp[k + 1][j + i];
                    } else if (k == j + i) {
                        left = &dp[j][k - 1];
                        right = &temp;
                    } else {
                        left = &dp[j][k - 1];
                        right = &dp[k + 1][j + i];
                    }
                    for (auto l : *left) {
                        for (auto r : *right) {
                            TreeNode *root = new TreeNode(k + 1);
                            root->left = l;
                            root->right = r;
                            dp[j][j + i].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

int main() { Solution{}.generateTrees(3); }