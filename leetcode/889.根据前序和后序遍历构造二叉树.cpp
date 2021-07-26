/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *constructFromPrePostHelper(vector<int> &preorder, vector<int> &postorder, int l1, int h1, int l2, int h2) {
        if (l1 > h1 || l2 > h2) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[l1]);
        if (l1 == h1) {
            return node;
        }
        ++l1;
        int i = l2;
        for (; i <= h2; ++i) {
            if (postorder[i] == preorder[l1]) {
                break;
            }
        }
        int step = i - l2;
        node->left = constructFromPrePostHelper(preorder, postorder, l1, l1 + step, l2, l2 + step);
        node->right = constructFromPrePostHelper(preorder, postorder, l1 + step + 1, h1, l2 + step + 1, h2 - 1);
        return node;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        TreeNode* res = constructFromPrePostHelper(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
        return res;
    }
};
// @lc code=end

