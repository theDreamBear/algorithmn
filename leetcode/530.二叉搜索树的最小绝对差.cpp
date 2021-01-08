/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int pre = -1;
    int ans;

    // 二叉树中序遍历递归版
    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        if (pre == -1) {
            pre = root->val;
            ans = INT_MAX;
        } else {
            int diff = root->val - pre;
            if (diff < ans) {
                ans = diff;
            }
            pre = root->val;
        }
        inorderTraversal(root->right);
    }


    int getMinimumDifference_recursion(TreeNode* root) {
        inorderTraversal(root);
        return ans;
    }

    // 二叉树中序遍历非递归版
    // 前序中序差异, 前序入队列时访问, 中序出队列时访问且 pop
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* node = st.top();
            if (pre == -1) {
                pre = node->val;
                ans = INT_MAX;
            } else {
                int diff = node->val - pre;
                if (diff < ans) {
                    ans = diff;
                }
                pre = node->val;
            }
            st.pop();
            if (node->right) {
                cur = node->right;
            }
        }
        return ans;
    }
};
// @lc code=end

