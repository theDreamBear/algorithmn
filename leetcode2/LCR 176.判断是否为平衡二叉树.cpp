/*
 * @lc app=leetcode.cn id=LCR 176 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 176] 判断是否为平衡二叉树
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
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }

    bool isBalanced1(TreeNode* root) {
        if (!root) {
            return true;
        }
        bool left = isBalanced1(root->left);
        bool right = isBalanced1(root->right);
        return left and right and abs(depth(root->left) - depth(root->right)) <= 1;
    }

    pair<bool, int> isBalancedHelper(TreeNode* root) {
        if (!root) {
            return {true, 0};
        }
        // 后序遍历
        auto left = isBalancedHelper(root->left);
        auto right = isBalancedHelper(root->right);
        if (!left.first || !right.first || abs(left.second - right.second) > 1) {
            return {false, 0};
        }
        return {true, max(left.second, right.second) + 1};
    }

    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isBalancedHelper(root).first;
    }


};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,3,3,null,null,4,4]\n
// @lcpr case=end

 */

