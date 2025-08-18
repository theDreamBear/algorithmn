/*
 * @lc app=leetcode.cn id=572 lang=cpp
 * @lcpr version=30204
 *
 * [572] 另一棵树的子树
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
    // (1, 12), (21, 1) 这种无法避免
    bool isSubtree_bad(TreeNode* root, TreeNode* subRoot) {
        auto series = [&](this auto&& dfs, TreeNode* node)->string {
            if (!node) return "#";
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            return to_string(node->val) + "(" + left + ", " + right + ")";
        };
        auto ls = series(root), rs = series(subRoot);
        return strstr(ls.c_str(), rs.c_str()) != NULL;
    }

    bool isSubtree2(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (!root or !subRoot) return false;
        auto check = [&](this auto&&dfs, TreeNode* l, TreeNode* r) {
            if (!l and !r) return true;
            if (!l or !r) return false;
            return l->val == r->val and dfs(l->left, r->left) and dfs(l->right, r->right);
        };
        if (root->val == subRoot->val) {
            if (check(root, subRoot)) return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) return true;
        if (!root or !subRoot) return false;

        auto height = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            return 1 + max(dfs(node->left), dfs(node->right));
        };
        int h = height(subRoot);
         auto check2 = [&](this auto&&dfs, TreeNode* l, TreeNode* r) {
            if (!l and !r) return true;
            if (!l or !r) return false;
            return l->val == r->val and dfs(l->left, r->left) and dfs(l->right, r->right);
        };

        auto check = [&](this auto&&dfs, TreeNode* l)->pair<int, bool> {
            if (!l) return {0, false};
            auto left = dfs(l->left), right = dfs(l->right);
            if (left.second or right.second) {
                return {0, true};
            }
            int nh = max(left.first, right.first) + 1;
            return {nh, nh == h and check2(l, subRoot)};
        };
        return check(root).second;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,5,1,2]\n[4,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,5,1,2,null,null,null,null,0]\n[4,1,2]\n
// @lcpr case=end

 */

