/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
    int sum = 0;
    int findTiltHelper(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = findTiltHelper(root->left);
        int right = findTiltHelper(root->right);
        sum += abs(left - right);
        return left + right + root->val;
    }

    int findTilt(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        findTiltHelper(root);
        return sum;
    }
};
// @lc code=end
