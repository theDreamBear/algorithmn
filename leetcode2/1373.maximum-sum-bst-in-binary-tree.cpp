/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 * @lcpr version=30204
 *
 * [1373] 二叉搜索子树的最大键值和
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
#include <map>
#include <set>
#include <string>
#include <string.h>
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
    int maxSumBST(TreeNode* root) {

        int ans = 0;

        auto post = [&](this auto&& dfs, TreeNode* node, int mm = INT_MIN, int mx = INT_MAX)->tuple<int, int, int> {
            // 可以
            if (!node) {
                return {0, INT_MAX, INT_MIN};
            }
            if (!node->left and !node->right) {
                ans = max(ans, node->val);
                return {node->val, node->val, node->val};
            }
            auto [sl, lmm, lmx] = dfs(node->left);
            auto [sr, rmm, rmx] = dfs(node->right);
            if (node->val <= lmx or node->val >= rmm) {
                return {0, INT_MIN, INT_MAX};
            }
            int sum = sl + sr + node->val;
            ans = max(ans, sum);
            return {sum, min(lmm, node->val), max(node->val, rmx)};
        };
        post(root);
        return ans;
    }

    int maxSumBST1(TreeNode* root) {

        int ans = 0;

        auto post = [&](this auto&& dfs, TreeNode* node, int mm = INT_MIN, int mx = INT_MAX)->tuple<int, int, int> {
            // 可以
            if (!node) {
                return {0, 0, 0};
            }
            if (!node->left and !node->right) {
                ans = max(ans, node->val);
                return {node->val, node->val, node->val};
            }
            auto [sl, lmm, lmx] = dfs(node->left);
            auto [sr, rmm, rmx] = dfs(node->right);

            if (sl != INT_MAX and sr != INT_MAX) {
                if (sl == 0 and sr == 0) {
                    ans = max(ans, node->val);
                    return {node->val, node->val, node->val};
                }
                if (sl == 0 and node->val < rmm) {
                    ans = max(ans, sr + node->val);
                    return {sr + node->val, node->val, rmx};
                }
                if (sr == 0 and node->val > lmx) {
                    ans = max(ans, sl + node->val);
                    return {sl + node->val, lmx, node->val};
                }
                if (node->val > lmx and node->val < rmm) {
                    int sum = sl + sr + node->val;
                    ans = max(ans, sum);
                    return {sum, lmm, rmx};
                }
            }
            return {INT_MAX, 0, 0};
        };
        post(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,null,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [-4,-2,-5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,3,null,6,3]\n
// @lcpr case=end

 */

