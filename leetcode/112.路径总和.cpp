/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (48.37%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    43.8K
 * Total Submissions: 90.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
class Solution {
public:
    bool b;
    bool hasPathSumHelper(TreeNode* root, int sum) {
        if (b == true) {
            return true;
        }
        if (root == NULL) {
            return false;
        }
        if (root->left == NULL && root->right == NULL && sum == root->val) {
            return true;
        }
        auto left = hasPathSumHelper(root->left, sum - root->val);
        auto right = hasPathSumHelper(root->right, sum - root->val);
        b = left | right;
        return b;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        b = false;
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        if (root->left == NULL) {
            return hasPathSumHelper(root->right, sum - root->val);
        }
        if (root->right == NULL) {
            return hasPathSumHelper(root->left, sum - root->val);
        }
        return hasPathSumHelper(root, sum);
    }
};
// @lc code=end

