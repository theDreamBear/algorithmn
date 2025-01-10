/*
 * @lc app=leetcode.cn id=993 lang=cpp
 * @lcpr version=30204
 *
 * [993] 二叉树的堂兄弟节点
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
    bool isCousins1(TreeNode* root, int x, int y) {
        if (x > y) swap(x, y);
        int d1 = -1, d2 = -2;
        auto get = [&](auto&& get, TreeNode* node, int depth) {
            if (!node) return false;
            bool left =  get(get, node->left, depth + 1);
            bool right = get(get, node->right, depth + 1);  
            if (left and right) {
                int x1 = node->left->val, x2 = node->right->val;
                if (x1 > x2) swap(x1, x2);
                if (x1 == x and x2 == y) {
                    d1 = -1, d2 = -2;
                    return false;
                }
                return true;
            }
            if (node->val == x) {
                d1 = depth;
                return true;
            }
            if (node->val == y) {
                d2 = depth;
                return true;
            }
            return left || right;
        };
        get(get, root, 0);
        return d1 == d2;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode* father = nullptr;
        int d = 0;
        auto dfs = [&](auto&& dfs, TreeNode* node, TreeNode* fa, int depth) {
            if (!node) return false;
            if (d and depth > d) return false;
            if (node->val == x || node->val == y) {
                if (d) {
                    return d == depth and fa != father;
                }
                d = depth;
                father = fa;
                return false;
            }
            return dfs(dfs, node->left, node, depth + 1) || dfs(dfs, node->right, node, depth + 1);
        };
        return dfs(dfs, root, nullptr, 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n4\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4,null,5]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4]\n2\n3\n
// @lcpr case=end

 */

