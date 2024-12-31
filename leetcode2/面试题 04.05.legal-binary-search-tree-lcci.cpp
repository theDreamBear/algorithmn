/*
 * @lc app=leetcode.cn id=面试题 04.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.05] 合法二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (!root or !root->left and !root->right) return true;
        long long pre = LLONG_MIN;
        auto dfs = [&](auto&& dfs, TreeNode* node) {
            if (!node) {
                return true;
            }
            auto left = dfs(dfs, node->left);
            if (!left or node->val <= pre) return false;
            pre = node->val;
            return dfs(dfs, node->right);
        };
        return dfs(dfs, root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2/ \1   3\n
// @lcpr case=end

// @lcpr case=start
// 5/ \1   4/ \3   6\n
// @lcpr case=end

 */

