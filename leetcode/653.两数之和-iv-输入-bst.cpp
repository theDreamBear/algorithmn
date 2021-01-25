/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
    void inorderVisit(TreeNode *node, vector<int> &nums) {
        if (node == NULL) {
            return;
        }
        if (node->left) {
            inorderVisit(node->left, nums);
        }
        nums.push_back(node->val);
        if (node->right) {
            inorderVisit(node->right, nums);
        }
    }

    /*
        空间换时间
    */
    bool findTarget1(TreeNode *root, int k) {
        vector<int> res;
        inorderVisit(root, res);
        int i = 0, j = res.size() - 1;
        while (i < j) {
            int sum = res[i] + res[j];
            if (sum > k) {
                --j;
            }
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                ++i;
            }
        }
        return false;
    }

    bool findTarget(TreeNode *root, int k) {
        // 中序遍历非递归
        stack<TreeNode *> small;
        stack<TreeNode *> big;
        TreeNode *lcur = root;
        TreeNode *rcur = root;
        int t = 0;
        // 0 都入栈
        // -1 右入栈
        // 1 左入栈
        while ((lcur && rcur) || (!small.empty() && !big.empty())) {
            while (t != -1 && lcur) {
                small.push(lcur);
                lcur = lcur->left;
            }
            while (t != 1 && rcur) {
                big.push(rcur);
                rcur = rcur->right;
            }
            lcur = small.top();
            rcur = big.top();
            // 相遇
            if (lcur == rcur) {
                return false;
            }
            int sum = lcur->val + rcur->val;
            // 找到
            if (sum == k) {
                return true;
            } else if (sum > k) {
                big.pop();
                rcur = rcur->left;
                t = -1;
            } else {
                small.pop();
                lcur = lcur->right;
                t = 1;
            }
        }
        return false;
    }
};
// @lc code=end
