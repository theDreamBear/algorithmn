/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
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
    /*
        暴力解法
    */
    int countNodes1(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }

    int treeDepth(TreeNode *root) {
        int n = 0;
        while (root) {
            ++n;
            root = root->left;
        }
        return n;
    }

    int nHash(TreeNode *node, int cur, int n) {
        if (!node) {
            return 0;
        }
        if (cur > n) {
            return 0;
        }
        if (cur == n) {
            if (!node->left) {
                return 0;
            }
            if (!node->right) {
                return 1;
            }
            return 2;
        }
        int left = nHash(node->left, cur + 1, n);
        int right = nHash(node->right, cur + 1, n);
        return left + right;
    }

    int countNodes2(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int depth = treeDepth(root);
        int n = pow(2, depth - 1) - 1;
        return n + nHash(root, 1, depth - 1);
    }

    bool exist(TreeNode *root, int bitmask, int depth) {
        TreeNode *node = root;
        for (int i = depth - 2; i >= 0 && node; --i) {
            int bit = (bitmask >> i) & 0x1;
            if (bit) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        return node;
    }

    /*
        官方解法
    */
    int countNodes3(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int depth = treeDepth(root);
        int low = pow(2, depth - 1);
        int high = pow(2, depth) - 1;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (exist(root, mid, depth)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        if (exist(root, high, depth)) {
            return high;
        }
        return low;
    }

    int countNodes(TreeNode *root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int left = treeDepth(root->left);
        int right = treeDepth(root->right);
        if (left == right) {
            return  countNodes(root->right) + (1 << left);
        } else {
            return countNodes(root->left) + (1 << right);
        }
    }
};
// @lc code=end
