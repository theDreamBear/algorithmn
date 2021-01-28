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

    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL) {
            return -1;
        }
        int left = findSecondMinimumValue(root->left);
        int right = findSecondMinimumValue(root->right);
        if (left == -1 && right == -1) {
            return -1;
        }
        if (left == -1) {
            return
        }
    }
};
// @lc code=end

