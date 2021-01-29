/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    void findSecondMinimumValueHelper(TreeNode* root, vector<int>& nums) {
        if (root == NULL) {
            return;
        }
        nums.push_back(root->val);
        findSecondMinimumValueHelper(root->left, nums);
        findSecondMinimumValueHelper(root->right, nums);
    }

    // 存起来
    int findSecondMinimumValue1(TreeNode* root) {
        vector<int> temp;
        findSecondMinimumValueHelper(root, temp);
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        if (temp.size() == 1) {
            return -1;
        }
        return temp[1];
    }

    /*
        找到除 small 以外最小的, 还是可能返回 small
    */
    int findSecondMinimumValueFinder(TreeNode* node, int small) {
        if (node->left == NULL) {
            return node->val;
        }
        int left = findSecondMinimumValueFinder(node->left, small);
        int right = findSecondMinimumValueFinder(node->right, small);
        if (left == small) {
            return right;
        }
        if (right == small) {
            return left;
        }
        return min(left, right);
    }

    /*
        递归方法需要引入第二参数 small, 或者设置全局变量
    */
    int findSecondMinimumValue2(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int val = findSecondMinimumValueFinder(root, root->val);
        return (val == root->val) ? -1 : val;
    }

    /*
        前序遍历找除根节点最小值
    */
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int sm = root->val;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->val != root->val) {
                if (sm == root->val) {
                    sm = cur->val;
                } else {
                    sm = min(sm, cur->val);
                }
            }
            cur = cur->right;
        }
        return (sm == root->val) ? -1 : sm;
    }
};
// @lc code=end

