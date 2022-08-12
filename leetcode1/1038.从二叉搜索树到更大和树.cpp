/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */

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
// 题目看三遍
class Solution {
public:
    // 右, 中 ，左
    // 逆中序遍历
    TreeNode* bstToGst(TreeNode* root) {
        int pre = 0;
#ifdef NI
        function<void(TreeNode* node)>  niInorder = [&] (TreeNode* node) {
            if (nullptr == node) {
                return;
            }
            niInorder(node->right);
            node->val += pre;
            pre = node->val;
            niInorder(node->left);
        };
        niInorder(root);
#else
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            cur->val += pre;
            pre = cur->val;
            cur = cur->left;
        }
#endif
        return root;
    }
};
// @lc code=end

