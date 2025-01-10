/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 * @lcpr version=30204
 *
 * [1022] 从根到叶的二进制数之和
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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](auto&& dfs, TreeNode* node, int pre) {
            if (!node) return;
            if (!node->left and !node->right) {
                ans += (pre << 1) + node->val;
                return;
            }
            dfs(dfs, node->left, (pre << 1) + node->val);
            dfs(dfs, node->right, (pre << 1) + node->val);
        };
        dfs(dfs, root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1,0,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

