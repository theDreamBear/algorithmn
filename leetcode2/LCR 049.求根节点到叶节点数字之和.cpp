/*
 * @lc app=leetcode.cn id=LCR 049 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 049] 求根节点到叶节点数字之和
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
    void preorder(TreeNode* node, int pre, int& ans) {
        if (!node) {
            return;
        }
        pre = pre * 10 + node->val;
        if (!node->left and !node->right) {
            ans += pre;
            return;
        }
        preorder(node->left, pre, ans);
        preorder(node->right, pre, ans);
    }

    int preorder(TreeNode* node, int pre) {
        if (!node) {
            return 0;
        }
        pre = pre * 10 + node->val;
        if (!node->left and !node->right) {
            return pre;
        }
        return preorder(node->left, pre) + preorder(node->right, pre);
    }


    int sumNumbers(TreeNode* root) {
        int ans = 0;
        // preorder(root, 0, ans);
        //return ans;
        return preorder(root, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,9,0,5,1]\n
// @lcpr case=end

 */

