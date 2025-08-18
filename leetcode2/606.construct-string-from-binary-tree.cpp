/*
 * @lc app=leetcode.cn id=606 lang=cpp
 * @lcpr version=30204
 *
 * [606] 根据二叉树创建字符串
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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        if (!root->left and !root->right) {
            return to_string(root->val);
        }
        auto left = tree2str(root->left);
        auto right = tree2str(root->right);
        if (right != "") {
            return to_string(root->val) + "(" + left + ")(" + right + ")";
        } else {
            return to_string(root->val) + "(" + left + ")";
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4]\n
// @lcpr case=end

 */

