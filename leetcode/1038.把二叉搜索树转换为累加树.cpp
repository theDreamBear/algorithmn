/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 把二叉搜索树转换为累加树
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
#include <numeric>

using namespace std;

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
    void inorderVisit(TreeNode* root, int& sum) {
        if (!root) {
            return;
        }
        inorderVisit(root->right, sum);
        root->val += sum;
        sum = root->val;
        inorderVisit(root->left, sum);
    }

    TreeNode* bstToGst1(TreeNode* root) {
        int sum = 0;
        inorderVisit(root, sum);
        return root;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            cur->val += sum;
            sum = cur->val;
            cur = cur->left;
        }
        return root;
    }
};
// @lc code=end

