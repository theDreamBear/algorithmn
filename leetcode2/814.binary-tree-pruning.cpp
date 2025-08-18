/*
 * @lc app=leetcode.cn id=814 lang=cpp
 * @lcpr version=30204
 *
 * [814] 二叉树剪枝
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
    TreeNode* pruneTree(TreeNode* root) {
        auto post = [&](this auto&& dfs, TreeNode* node)->pair<TreeNode*, int> {
            if (!node) {
                return {nullptr, 0};
            }
            auto left = dfs(node->left), right = dfs(node->right);
            node->left = left.second == 0 ? nullptr: left.first;
            node->right = right.second == 0 ? nullptr: right.first;
            return {node, left.second || right.second || node->val != 0};
        };
        auto ans = post(root);
        return ans.second == 0 ? nullptr: ans.first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,1,0,0,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1,1,0,1,0]\n
// @lcpr case=end

 */

