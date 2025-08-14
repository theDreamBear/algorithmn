/*
 * @lc app=leetcode.cn id=671 lang=cpp
 * @lcpr version=30204
 *
 * [671] 二叉树中第二小的节点
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
    int findSecondMinimumValue1(TreeNode* root) {
        int mx = root->val, mmx = -1;
        auto dfs = [&](this auto&& dfs, TreeNode* node) {
            if (!node) {
                return;
            }
            if (node->val > mx) {
                if (mmx == -1 or node->val < mmx) {
                    mmx = node->val;
                }
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return mmx;
    }

    int findSecondMinimumValue(TreeNode* root) {
        if (!root->left and !root->right) return -1;
        int left = root->left->val == root->val ? findSecondMinimumValue(root->left) : root->left->val;
        int right = root->right->val == root->val ? findSecondMinimumValue(root->right) : root->right->val;
        if (left == -1 and right == -1) {
            return -1;
        }
        if (left == -1) return right;
        if (right == -1) return left;
        return min(left, right);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,5,null,null,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

 */

