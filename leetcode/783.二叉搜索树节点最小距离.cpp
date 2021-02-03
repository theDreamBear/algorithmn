/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
    int ans;
    int pre = -1;
    int minDiffInBST(TreeNode* root) {
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
