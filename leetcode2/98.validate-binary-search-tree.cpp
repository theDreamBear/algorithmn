/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30114
 *
 * [98] 验证二叉搜索树
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
    // 中序
    bool isValidBST1(TreeNode* root) {
        if (!root) {
            return true;
        }
        TreeNode* pre = nullptr;
        function<bool(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return true;
            }
            // 写了个蛇皮
            return dfs(node->left) and ((!pre || pre->val < node->val) ? (pre = node, true) : false) and dfs(node->right);
        };
        return dfs(root);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        auto pre = [&](this auto&& dfs, TreeNode* node, long long mm = LLONG_MIN, long long mx = LLONG_MAX) {
            if (!node) return true;
            long long x = node->val;
            return mm < x and x < mx and dfs(node->left, mm, x) and dfs(node->right, x, mx);
        };
        return pre(root);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

