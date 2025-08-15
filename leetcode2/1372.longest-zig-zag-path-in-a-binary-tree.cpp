/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 * @lcpr version=30204
 *
 * [1372] 二叉树中的最长交错路径
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
    int longestZigZag1_brute(TreeNode* root) {
        int ans = 0;
        auto vis = [&](this auto&& dfs, TreeNode* node, int i, int depth = 0) {
            if (!node) return;
            if (i % 2 == 0) {
                if (!node->left) {
                    ans = max(ans, depth);
                    return;
                }
                dfs(node->left, i + 1, depth + 1);
            } else {
                if (!node->right) {
                    ans = max(ans, depth);
                    return;
                }
                dfs(node->right, i + 1, depth + 1);
            }
        };

        auto pre = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;

            vis(node, 0);
            vis(node, 1);

            dfs(node->left);
            dfs(node->right);
        };

        pre(root);
        return ans;
    }

    int longestZigZag(TreeNode* root) {
        int ans = 0;
        auto vis = [&](this auto&& dfs, TreeNode* node, int i, int depth = 0) {
            if (!node) return;
            ans = max(ans, depth);
            if (i % 2 == 0) {
                if (node->left) dfs(node->left, i + 1, depth + 1);
                if (node->right) dfs(node->right, 0, 1);

            } else {
                if (node->left) dfs(node->left, 1, 1);
                if (node->right) dfs(node->right, i + 1, depth + 1);
            }
        };
        vis(root, 0);
        vis(root, 1);
        return ans;
    }

    // 后序遍历
    int longestZigZag_post(TreeNode* root) {
        int ans = 0;
        auto post = [&](this auto&& dfs, TreeNode* node)->pair<int, int> {
            if (!node) return {-1, -1};
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            ans = max({ans, left.second + 1, right.first + 1});
            return {left.second + 1, right.first + 1};
        };
        post(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,null,1,null,null,1,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

