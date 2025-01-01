/*
 * @lc app=leetcode.cn id=面试题 04.08 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.08] 首个共同祖先
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 1 1 0 x
    // a b 1 x
    // 1 0 0 1
    // 0 1 0 2
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        auto left = lowestCommonAncestor1(root->left, p, q);
        auto right = lowestCommonAncestor1(root->right, p, q);
        if ((left and right) or (root == p or root == q)) return root;
        return left != nullptr ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root or root == p or root == q) {
            return root;
        }
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left and right) return root;
        return left != nullptr ? left : right;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

 */

