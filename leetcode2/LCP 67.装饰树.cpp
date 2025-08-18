/*
 * @lc app=leetcode.cn id=LCP 67 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 67] 装饰树
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
    TreeNode* expandBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left and !root->right) {
            return root;
        }
        auto left = expandBinaryTree(root->left);
        auto right = expandBinaryTree(root->right);
        if (right) {
            TreeNode* nd = new TreeNode(-1);
            nd->right = right;
            root->right = nd;
        }
        if (left) {
            TreeNode* nd = new TreeNode(-1);
            nd->left = left;
            root->left = nd;
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,5,6]`>\n
// @lcpr case=end

// @lcpr case=start
// [3,1,7,3,8,null,4]`>\n
// @lcpr case=end

 */

