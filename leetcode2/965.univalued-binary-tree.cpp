/*
 * @lc app=leetcode.cn id=965 lang=cpp
 * @lcpr version=30204
 *
 * [965] 单值二叉树
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
    bool isUnivalTree(TreeNode* root) {
        int v = INT_MAX;
        auto dfs = [&](auto&& dfs, TreeNode* node) {
            if (!node) return true;
            if (v != INT_MAX and v != node->val) return false;
            v = node->val;
            return dfs(dfs, node->left) and dfs(dfs, node->right);
        };
        return dfs(dfs, root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,5,2]\n
// @lcpr case=end

 */

