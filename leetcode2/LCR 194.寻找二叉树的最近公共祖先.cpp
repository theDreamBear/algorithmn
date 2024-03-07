/*
 * @lc app=leetcode.cn id=LCR 194 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 194] 二叉树的最近公共祖先
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
    pair<TreeNode*, int> lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return {NULL, 0};
        }
        auto left = lowestCommonAncestorHelper(root->left, p, q);
        auto right = lowestCommonAncestorHelper(root->right, p, q);
        if (!left.first && !right.first) {
            if (root->val == p->val || root->val == q->val) {
                return {root, 1};
            }
            return {NULL, 0};
        }
        if (!left.first) {
            if (root->val == p->val || root->val == q->val) {
                return {root, 2};
            }
            return right;
        }
        if (!right.first) {
            if (root->val == p->val || root->val == q->val) {
                return {root, 2};
            }
            return left;
        }
        return {root, 2};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestorHelper(root, p, q).first;
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

