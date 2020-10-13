/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
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
    bool isValidBST1(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        st.push(cur);
        TreeNode* pre = NULL;
        while (!st.empty()) {
            cur = st.top();
            if (cur) {
                // 右
                st.pop();
                if (cur->right) {
                    st.push(cur->right);
                }
                // 中
                st.push(cur);
                st.push(NULL);
                //左
                if (cur->left) {
                    st.push(cur->left);
                }
            } else {
                st.pop();
                cur = st.top();
                st.pop();
                if (cur && cur->val <= pre->val) {
                    return false;
                }
                pre = cur;
            }
        }
        return true;
    }

    // 中序遍历
    bool isValidBST2(TreeNode* root) {
        if (NULL == root) {
            return true;
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
            st.pop();
            if (pre && cur->val <= pre->val) {
                return false;
            }
            pre = cur;
            cur = cur->right;
        }
        return true;
    }

    TreeNode* pre = NULL;
    // dfs
    bool isValidBSTHelper(TreeNode* root) {
        if (NULL == root) {
            return true;
        }
        if (!isValidBSTHelper(root->left) || (pre && root->val <= pre->val)) {
            return false;
        }
        pre = root;
        return isValidBSTHelper(root->right);
    }
    bool isValidBST(TreeNode* root) { return isValidBSTHelper(root); }
};
// @lc code=end
