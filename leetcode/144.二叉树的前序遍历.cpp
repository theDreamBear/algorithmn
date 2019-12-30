/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (63.00%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    57.7K
 * Total Submissions: 91.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

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
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define NULL 0
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversalDiversion(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        ans.push_back(root->val);
        auto left = preorderTraversalDiversion(root->left);
        copy(left.begin(), left.end(), back_inserter(ans));
        left = preorderTraversalDiversion(root->right);
        copy(left.begin(), left.end(), back_inserter(ans));
        return ans;
    }

    vector<int> preorderTraversalCommon(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        // 已访问节点
        stack<TreeNode*> stack;
        // 当前待访问节点
        TreeNode* cur = root;
        while(cur != NULL || !stack.empty()) {
            while( cur != NULL ) {
                ans.push_back(cur->val);
                stack.push(cur);
                cur = cur -> left;
            }
            if (cur == NULL) {
                cur = stack.top();
                stack.pop();
                cur = cur->right;
            }
        }
        return ans;
    }

// 注意循环的退出条件以及问题的结束条件
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        // 已访问节点
        stack<TreeNode*> stack;
        // 当前待访问节点
        TreeNode* cur = root;
        ans.push_back(cur->val);
        stack.push(cur);
        while(!stack.empty()) {
            gg:
            while( true ) {
                if (cur->left != NULL) {
                    cur = cur -> left;
                    ans.push_back(cur->val);
                    stack.push(cur);
                } else {
                    break;
                }
            }
            while (!stack.empty()) {
                cur = stack.top();
                stack.pop();
                if (cur->right != NULL) {
                    cur = cur->right;
                    ans.push_back(cur->val);
                    stack.push(cur);
                    goto gg;
                }
            }
            break;
        }
        return ans;
    }

};
// @lc code=end

