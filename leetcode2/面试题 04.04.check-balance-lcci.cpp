/*
 * @lc app=leetcode.cn id=面试题 04.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.04] 检查平衡性
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
    bool isBalanced(TreeNode* root) {  
        auto h = [&](auto&& h, TreeNode* node)->pair<bool, int> {
            if (!node) return {1, 0};
            auto [b1, left] = h(h, node->left);
            auto [b2, right ] = h(h, node->right);
            return {b1 and b2 and max(left, right) - min(left, right) <= 1, max(left, right) + 1};
        };
        return h(h, root).first;
    }
};
// @lc code=end



