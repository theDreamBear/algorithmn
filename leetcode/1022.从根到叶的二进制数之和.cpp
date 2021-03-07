/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
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
    void preorderTraversal(TreeNode* node, int pre, int& sum) {
        if (node == NULL) {
            return;
        }
        pre = (pre << 1) ^ node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += pre;
            return;
        }
        preorderTraversal(node->left, pre, sum);
        preorderTraversal(node->right, pre, sum);
    }

    int sumRootToLeaf(TreeNode *root) {
        int ans = 0;
        preorderTraversal(root, 0, ans);
        return ans;
    }
};
// @lc code=end
