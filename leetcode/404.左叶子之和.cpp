/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void sumOfLeftLeavesHelper(TreeNode* node, int& sum) {
        if (node == NULL) {
            return;
        }
        //   先序遍历
        if (node->left && node->left->left == NULL && node->left->right == NULL) {
            sum += node->left->val;
        }
        sumOfLeftLeavesHelper(node->left, sum);
        sumOfLeftLeavesHelper(node->right, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumOfLeftLeavesHelper(root, ans);
        return ans;
    }
};
// @lc code=end

