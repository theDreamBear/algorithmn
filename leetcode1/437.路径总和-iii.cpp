/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSumHelper(TreeNode* root, int targetSum, vector<long long>& data) {
        if (root == nullptr) {
            return 0;
        }
        int ans = 0;
        if (root->val == targetSum) {
            ++ans;
        }
        for (auto& v : data) {
            v += root->val;
            if (v == targetSum) {
                ++ans;
            }
        }
        data.push_back(root->val);

        int left = pathSumHelper(root->left, targetSum, data);
        int right = pathSumHelper(root->right, targetSum, data);

        ans += (left + right);
        for (auto& v : data) {
            v -= root->val;
        }
        data.pop_back();

        return ans;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> data;
        return pathSumHelper(root, targetSum, data);
    }
};
// @lc code=end

