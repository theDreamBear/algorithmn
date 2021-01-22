/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    /*
        二叉树层次遍历
    */
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            int sz = st.size();
            long long val = 0;
            int times = 0;
            for (int i = 0; i < sz; ++ i) {
                TreeNode* cur = st.front(); st.pop();
                ++times;
                val += cur->val;
                if (cur->left) {
                    st.push(cur->left);
                }
                if (cur->right) {
                    st.push(cur->right);
                }
            }
            result.push_back(val * 1.0 / times);
        }
        return result;
    }
};
// @lc code=end

