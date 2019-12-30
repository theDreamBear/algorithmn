/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (63.46%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    35.4K
 * Total Submissions: 55.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
//#include<algorithmn>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    // 树的层次遍历, 利用 stack, 逆序结果
    vector<vector<int> > levelOrderBottomNonRecursion(TreeNode* root) {
        vector<vector<int> > ans;
        if (root == NULL) {
            return ans;
        }
        stack<vector<int>> temp;
        queue<TreeNode*> st;
        //temp.push(vector<int>{root->val});
        st.push(root);
        while(!st.empty()) {
            vector<int> ve;
            int sz = st.size();
            for(int i = 0; i < sz; ++i) {
                auto node = st.front(); st.pop();
                ve.push_back(node->val);
                if (node->left != NULL) {
                    st.push(node->left);
                }
                if (node->right != NULL) {
                    st.push(node->right);
                }
            }
            temp.push(ve);
        }
        while(!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        return ans;
    }

    void levelOrderBottomHelper(vector<vector<int>> &res, TreeNode* root, int depth) {
        if (root == NULL) {
            return;
        }
        if (res.size() < depth + 1) {
            vector<int> re;
            res.push_back(re);
        }
        res[depth].push_back(root->val);
        levelOrderBottomHelper(res, root->left, depth + 1);
        levelOrderBottomHelper(res, root->right, depth + 1);
    } 

    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        levelOrderBottomHelper(ans, root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

