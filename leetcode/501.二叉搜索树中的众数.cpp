/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    map<int, int> h;
    void traversal(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        traversal(root->left);
        ++h[root->val];
        traversal(root->right);
    }

    /*
        二叉搜索树中序遍历
        这个题的难点, 1. 找到所有的众数
    */
    vector<int> findMode_violate(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        traversal(root);
        int maxTimes = 0;
        for (auto& kv : h) {
            if (kv.second > maxTimes) {
                maxTimes = kv.second;
            }
        }

        for (auto& kv : h) {
            if (kv.second == maxTimes) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }

    vector<int> ans;

    int count = 0;
    int max_count = 0;
    int pre = 0;
    bool start = false;

    void inorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorderTraversal(root->left);
        if (!start) {
            count = 1;
            max_count = 1;
            pre = root->val;
            start = true;
        } else {
            if (root->val == pre) {
                ++count;
                if (count > max_count) {
                    max_count = count;
                }
            } else {
                count = 1;
                pre = root->val;

            }
        }
        inorderTraversal(root->right);
    }

     void inorderTraversal_times(TreeNode* root, int times) {
        if (root == NULL) {
            return;
        }
        inorderTraversal_times(root->left, times);
        if (!start) {
            count = 1;
            pre = root->val;
            start = true;
        } else {
            if (root->val == pre) {
                ++count;
            } else {
                count = 1;
                pre = root->val;

            }
        }
        if (count == times) {
            ans.push_back(pre);
        }
        inorderTraversal_times(root->right, times);
    }

    vector<int> findMode(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }
        start = false;
        inorderTraversal(root);
        start = false;
        inorderTraversal_times(root, max_count);
        return ans;
    }
};
// @lc code=end

