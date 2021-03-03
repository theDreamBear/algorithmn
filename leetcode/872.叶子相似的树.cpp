/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
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
    void prerderTraversal(TreeNode* root, vector<int>& data) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            data.push_back(root->val);
        }
        prerderTraversal(root->left, data);
        prerderTraversal(root->right, data);
    }

    /*
        递归先序遍历  O(n) + o(n)
    */
    bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
        vector<int> left, right;
        prerderTraversal(root1, left);
        prerderTraversal(root2, right);
        if (left.size() != right.size()) {
            return false;
        }
        for (int i = 0; i < left.size(); ++i) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }

    TreeNode* getOne(stack<TreeNode*>& st, TreeNode* node) {
        TreeNode* cur = node;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->left == NULL && cur->right == NULL) {
                return cur;
            }
            cur = cur->right;
        }
        return NULL;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // 先序遍历非递归
        stack<TreeNode*> left, right;
        TreeNode* cur1 = getOne(left, root1);
        TreeNode* cur2 = getOne(right, root2);
        while (cur1 && cur2) {
            if (cur1->val != cur2->val) {
                return false;
            }
            cur1 = getOne(left, NULL);
            cur2 = getOne(right, NULL);
        }
        if (cur1 == NULL && cur2 == NULL) {
            return true;
        }
        if (cur1 && cur2 && cur1->val == cur2->val) {
            return true;
        }
        return false;
    }
};
// @lc code=end
