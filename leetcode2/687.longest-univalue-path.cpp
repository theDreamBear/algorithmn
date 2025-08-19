/*
 * @lc app=leetcode.cn id=687 lang=cpp
 * @lcpr version=30204
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int ans = 1;
        auto post = [&](this auto&& dfs, TreeNode* node) {
            if (!node) {
                return 0;
            }
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            if (!left and !right) {
                return 1;
            }
            int len = 1;
            int ll = 0, rr = 0;
            if (left) {
                if (node->left->val == node->val) {
                    ll = left;
                    len += left;
                }
            }
            if (right) {
                if (node->right->val == node->val) {
                    rr = right;
                    len += right;
                }
            }
            ans = max(ans, len);
            return max(ll, rr) + 1;
        };
        post(root);
        return ans - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,5,1,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,5,4,4,5]\n
// @lcpr case=end

 */

