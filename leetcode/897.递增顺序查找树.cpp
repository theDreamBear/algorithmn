/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
    void inorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left, nodes);
        nodes.push_back(root);
        inorderTraversal(root->right, nodes);
    }

    TreeNode* increasingBST1(TreeNode* root) {
        vector<TreeNode*> ans;
        inorderTraversal(root, ans);
        for (int i = 1; i < ans.size(); ++i) {
            ans[i - 1]->left = NULL;
            ans[i - 1]->right = ans[i];
        }
        ans.back()->left = NULL;
        return ans[0];
    }


    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        TreeNode* newRoot = NULL;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if (pre == NULL) {
                newRoot = cur;
            } else {
                pre->right = cur;
            }
            cur->left = NULL;
            pre = cur;
            st.pop();
            cur = cur->right;
        }
        return newRoot;
    }
};
// @lc code=end

