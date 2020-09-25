/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include<vector>
#include<unordered_set>
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
    struct Helper {
        unordered_set<TreeNode*> addedSet;
        void add(TreeNode* node) {
            addedSet.insert(node);
        }   
        bool notAdd(TreeNode* node) {
            return addedSet.find(node) == addedSet.end();
        }
};

    
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> nodeStack;
        Helper h;
        TreeNode* cur = root;
        while (cur || !nodeStack.empty()) {
            while (cur && h.notAdd(cur)) {
                //cout << cur->val << endl;
                h.add(cur);
                nodeStack.push(cur);
                cur = cur->left;
            }
            cur = nodeStack.top();
            if (cur->right == NULL || !h.notAdd(cur->right)) {
                ans.push_back(cur->val);
                cur = NULL;
                nodeStack.pop();
                continue;
            }
            cur = cur->right;
        }
        return ans;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            if (NULL == cur->right || cur->right == pre) {
                ans.push_back(cur->val);
                pre = cur;
                st.pop();
                cur = NULL;
            } else {
                cur = cur->right;
            }
        }
        return ans;
    }

     vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (NULL == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;

        st.push(cur);
        while (!st.empty()) {
            while (cur && cur->left) {
                cur = cur->left;
                st.push(cur);
            }
            // cur top() || null
            // top
            if (!cur) {
                cur = st.top();
            }
            if (cur->right == NULL || cur->right == pre) {
                ans.push_back(cur->val);
                pre = cur;
                st.pop();
                cur = NULL;
            } else {
                cur = cur->right;
                 st.push(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

