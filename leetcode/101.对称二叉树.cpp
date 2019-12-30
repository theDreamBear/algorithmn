/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (49.23%)
 * Likes:    547
 * Dislikes: 0
 * Total Accepted:    80K
 * Total Submissions: 162.3K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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

// #define NULL 0
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include<stack>
using namespace std;
class Solution {
public:
    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        if (left == NULL || right == NULL) {
            return false;
        }
        if (left->val == right->val) {
            return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
        }
        return false;
    }

    // 递归
    bool isSymmetricDiversion(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }

    // 非递归, 利用先序遍历非递归
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        stack<TreeNode*> stackkLeft, stackRight;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        while ( (left != NULL && right != NULL) || ( !stackkLeft.empty() && !stackRight.empty() ) ) {
            while(left != NULL && right != NULL) {
                if (left->val != right->val) {
                    return false;
                }
                stackkLeft.push(left);
                stackRight.push(right);

                left = left->left;
                right = right->right;
            }
            if (left == right && left == NULL) {
                left = stackkLeft.top(); stackkLeft.pop();
                right = stackRight.top(); stackRight.pop();
                left = left->right;
                right = right->left;
            } else {
                return false;
            }
        }
        return left == right && left == NULL;
    }
};
// @lc code=end

