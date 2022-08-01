/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (nullptr == root) {
            return ans;
        }
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node) {
                temp.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else {
                ans.push_back(temp);
                temp.clear();
                // 队列为空
                if (q.empty()) {
                    // 比避免死循环
                    break;
                }
                q.push(nullptr);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

