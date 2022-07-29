/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder1(TreeNode* root) {
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
        return ans;
    }

    void addOrRemoveDepth(TreeNode* node, int depth) {
        node->val ^= (depth << 16);
    }

    int getDepth(TreeNode* node) {
        if (node->val >= 0) {
            return (node->val >> 16);
        } else {
            return (node->val >> 16) ^ -1;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (nullptr == root) {
            return ans;
        }
        queue<TreeNode*> q;
        vector<int> temp;
        int depth = 0;
        addOrRemoveDepth(root, depth);
        q.push(root);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int curDepth = getDepth(node);
            addOrRemoveDepth(node, curDepth);
            if (curDepth > depth) {
                ans.push_back(temp);
                temp.clear();
                depth = curDepth;
            }
            temp.push_back(node->val);
            if (node->left) {
                addOrRemoveDepth(node->left, depth + 1);
                q.push(node->left);
            }
            if (node->right) {
                addOrRemoveDepth(node->right, depth + 1);
                q.push(node->right);
            }
        }
        if (!temp.empty()) {
            ans.push_back(temp);
        }
        return ans;
    }
};

// @lc code=end

