/*
 * @lc app=leetcode.cn id=LCR 193 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 193] 二叉搜索树的最近公共祖先
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

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
    /*
        没有利用二叉搜索树的性质
    */
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        TreeNode* left = lowestCommonAncestor1(root->left, p , q);
        TreeNode* right = lowestCommonAncestor1(root->right, p, q);
        if (root->val == p->val || root->val == q->val || left && right) {
            return root;
        }
        if (!left and !right) {
            return NULL;
        }
        if (!left) {
            return right;
        }
        return left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return NULL;
        }
        if (p->val > q->val) {
            swap(p, q);
        }
        if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (root->val == p->val || root->val == q->val || left && right) {
            return root;
        }
        if (!left and !right) {
            return NULL;
        }
        if (!left) {
            return right;
        }
        return left;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

