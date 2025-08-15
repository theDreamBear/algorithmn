/*
 * @lc app=leetcode.cn id=623 lang=cpp
 * @lcpr version=30204
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* r = new TreeNode(val);
            r->left = root;
            return r;
        }
        auto pre = [&](this auto&& dfs, TreeNode* node, int d) {
            if (!node) {
                return;
            }
            if (d + 1 == depth) {
                TreeNode* l = new TreeNode(val);
                l->left = node->left;
                node->left = l;

                TreeNode* r = new TreeNode(val);
                r->right = node->right;
                node->right = r;
                return;
            }
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        };
        pre(root, 1);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,6,3,1,5]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [4,2,null,3,1]\n1\n3\n
// @lcpr case=end

 */

