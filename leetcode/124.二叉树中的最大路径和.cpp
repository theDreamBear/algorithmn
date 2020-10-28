// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem124.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <climits>
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
    /*
        后序遍历
    */
    int maxPathSumHelper(TreeNode* root, int& maxValue) {
        if (NULL == root) {
            return 0;
        }
        int left = maxPathSumHelper(root->left, maxValue);
        int right = maxPathSumHelper(root->right, maxValue);
        
        int now = root->val;
        if (left > 0) {
            now += left;
        }
        if (right > 0) {
            now += right;
        }
        if (now > maxValue) {
            maxValue = now;
        }
        int sub = min(left, right);
        if (sub > 0) {
            now -= sub;
        }
        return now;
    }

    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        maxPathSumHelper(root, maxValue, 0);
        return maxValue;
    }
};
// @lc code=end

