/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

#include<vector>
#include<stack>
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
    vector<int> inorderTraversal_common_template(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        st.push(cur);
        while (!st.empty()) {
            cur = st.top();
            if (NULL != cur) {
                st.pop();
                // 右
                if (NULL != cur->right) {
                    st.push(cur->right);
                }
                // 中
                st.push(cur);
                st.push(NULL);
                // 左
                if (NULL != cur->left) {
                    st.push(cur->left);
                }
            } else {
                st.pop();
                cur = st.top();
                ans.push_back(cur->val);
                st.pop();
            }
        }
        return ans;
    }

    /*
    排除已知算法自己的思路
    1. 出栈时机
        a. cur = st.pop(); st.pop(); cur = cur->right;}
    2. 是否需要先入栈,可以
    */
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur =  cur->left;
            }
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            cur = cur->right; 
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        st.push(cur);
        while (!st.empty()) {
            while (cur && cur->left) {
                cur = cur->left;
                st.push(cur->left);
            }
            // 最左节点 or null
            if (!cur) {
                cur = st.top();
            }
            ans.push_back(cur->val);
            
            st.pop();
            cur = cur->right;
            if (cur) {
                st.push(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

