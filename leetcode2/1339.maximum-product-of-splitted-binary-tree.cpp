/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 * @lcpr version=30204
 *
 * [1339] 分裂二叉树的最大乘积
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
    int maxProduct(TreeNode* root) {
        auto sum = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            return node->val + dfs(node->left) + dfs(node->right);
        };
        int total = sum(root);
        int hald = total / 2;
        long long ans = 0;
        auto post = [&](this auto&& dfs, TreeNode* node)->int {
            if (!node) return 0;
            long long l = dfs(node->left);
            long long r = dfs(node->right);
            ans = max({ans, l * (total - l), r * (total - r)});
            return l + r + node->val;
        };
        post(root);
        return ans % int(1e9 + 7);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2,3,4,null,null,5,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,9,10,7,8,6,5,4,11,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

