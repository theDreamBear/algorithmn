/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 * @lcpr version=30204
 *
 * [1080] 根到叶路径上的不足节点
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (!root) return nullptr;
        auto post = [&](this auto&& dfs, TreeNode* node, int s)->TreeNode* {
            if (!node) {
                return nullptr;
            }
            if (!node->left and !node->right) {
                return s + node->val < limit ? nullptr : node;
            }
            node->left = dfs(node->left, s + node->val);
            node->right = dfs(node->right, s + node->val);
            if (!node->left and !node->right) {
                return nullptr;
            }
            return !node->left and !node->right ? nullptr : node;
        };
        return post(root, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,17,4,7,1,null,null,5,3]\n22\n
// @lcpr case=end

// @lcpr case=start
// [1,2,-3,-5,null,4,null]\n-1\n
// @lcpr case=end

 */

