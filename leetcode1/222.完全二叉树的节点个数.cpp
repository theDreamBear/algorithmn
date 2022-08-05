/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int getDepth(TreeNode* node, TreeNode* TreeNode::*child) {
        if (!node) {
            return 0;
        }
        int ans = 0;
        while (node) {
            ++ans;
            node = node->*child;
        }
        return ans;
    }

    int countNodes1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 1;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        if (root->left) {
            ll = getDepth(root->left, &TreeNode::left);
            lr = getDepth(root->left, &TreeNode::right);
            if (ll == lr) {
                ans += (pow(2, ll) - 1);
                return ans + countNodes(root->right);
            }
        }
        if (root->right) {
            rl = getDepth(root->right, &TreeNode::left);
            rr = getDepth(root->right, &TreeNode::right);
            if (rl == rr) {
                ans += (pow(2, rl) - 1);
                return ans + countNodes(root->left);
            }
        }
        return ans;
    }

    int countNodes2(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = getDepth(root, &TreeNode::left);
        int r = getDepth(root, &TreeNode::right);
        if (l == r) {
            return pow(2, l) - 1;
        }
        return 1 + countNodes2(root->left) + countNodes(root->right);
    }

    bool exist(TreeNode *node, int val, int width) {
        while (nullptr != node && width > 0) {
            int v = (val >> (width - 1)) & 0x1;
            if (v == 0) {
                node = node->left;
            } else {
                node = node->right;
            }
            --width;
        }
        return node != nullptr;
    }
    // 2分法；
    int countNodes(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int depth = getDepth(root, &TreeNode::left);
        int low = 0;
        int upper = pow(2, depth - 1) - 1;
        int high = upper;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (exist(root, mid, depth - 1)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (exist(root, high, depth - 1)) {
            return upper + 1 + high;
        }
        return upper + 1 + low;
    }
};
// @lc code=end

