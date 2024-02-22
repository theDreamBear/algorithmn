/*
 * @lc app=leetcode.cn id=LCR 144 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 144] 翻转二叉树
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree1(TreeNode* root) {
        if (NULL == root) {
            return root;
        }
        swap(root->left, root->right);
        mirrorTree1(root->left);
        mirrorTree1(root->right);
        return root;
    }

    TreeNode* mirrorTree(TreeNode* root) {
        if (NULL == root) {
            return NULL;
        }
        // 后序
        auto left = mirrorTree(root->left);
        auto right = mirrorTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,9,8,3,2,4]\n
// @lcpr case=end

 */

