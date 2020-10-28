/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

#include <iostream>
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
    /*
    先序优先遍历
    */
    void dfs(vector<vector<int>>& result, vector<int> current, int currentSum,
             TreeNode* root, const int sum) {
        if (NULL == root) {
            return;
        }
        current.push_back(root->val);
        currentSum += root->val;
        if (NULL == root->left && NULL == root->right) {
            if (currentSum == sum) {
                result.push_back(current);
            }
            return;
        }
        dfs(result, current, currentSum, root->left, sum);
        dfs(result, current, currentSum, root->right, sum);
        current.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        dfs(result, vector<int>{}, 0, root, sum);
        return result;
    }
};
// @lc code=end
