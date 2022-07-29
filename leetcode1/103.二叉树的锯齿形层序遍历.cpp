/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (nullptr == root) {
            return ans;
        }
        queue<TreeNode*> q;
        vector<int> temp;
        q.push(root);
        q.push(nullptr);
        bool flag = true;
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
                if (!flag) {
                    reverse(temp.begin(), temp.end());
                }
                flag = !flag;
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
        return ans;
    }
};
// @lc code=end

