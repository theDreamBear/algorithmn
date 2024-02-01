/*
 * @lc app=leetcode.cn id=226 lang=cpp
 * @lcpr version=30114
 *
 * [226] 翻转二叉树
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
    /*
        函数定义： 函数返回一个翻转的二叉树
    */
    TreeNode* invertTree1(TreeNode* root) {
        // 对于空节点， 本身就是翻转的
        if (!root) {
            return NULL;
        }
        /*
            后序遍历
        */
        auto left = invertTree(root->left);
        auto right = invertTree(root->right);
        // 保证了返回是一个翻转的二叉树
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        // 先序遍历， 这个理论上更容易理解， 每一个节点翻转一次
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,7,1,3,6,9]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

