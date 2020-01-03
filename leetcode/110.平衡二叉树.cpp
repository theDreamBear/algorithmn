/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (49.35%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    42.3K
 * Total Submissions: 85.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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
#include <iostream>

using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
// struct HightNode {
//     TreeNode* node;
//     int height;
//     HightNode(TreeNode* n):node(n){
//         height = 0;
//     }
// };

class Solution {
public:
    bool b;
    int isBalancedHelper(TreeNode* root) {
        if (root == NULL || b == true) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        int left = isBalancedHelper(root->left);
        int right = isBalancedHelper(root->right);
        if (left < right) {
            swap(left, right);
        }
        if (left - right >= 2) {
            b = true;
            return 0;
        }
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        b = false;
        isBalancedHelper(root);
        return !b;
    }
};
// @lc code=end

