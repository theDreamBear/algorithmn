/*
 * @lc app=leetcode.cn id=998 lang=cpp
 * @lcpr version=30204
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree1(TreeNode* root, int val) {
        if (val > root->val) {
            return new TreeNode(val, root,  nullptr);
        }

        auto insert = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return false;
            if (dfs(node->right)) {
                return true;
            }
            if (node->val > val) {
                // 替代node的右节点
                TreeNode* nd = new TreeNode(val);
                nd->left = node->right;
                node->right = nd;
                return true;
            }
            return false;
        };
        insert(root);
        return root;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode** pp = &root;
        while (*pp and val < (*pp)->val) {
            pp = &(*pp)->right;
        }
        *pp = new TreeNode(val, *pp, nullptr);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,3,null,null,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [5,2,4,null,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,2,3,null,1]\n4\n
// @lcpr case=end

 */

