/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
class Solution {
public:
     void sumNumbersHelper(int& sum, int current, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        current = 10 * current + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += current;
            return;
        }
        sumNumbersHelper(sum, current, root->left);
        sumNumbersHelper(sum, current, root->right);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbersHelper(sum, 0, root);
        return sum;
    }
};
// @lc code=end

