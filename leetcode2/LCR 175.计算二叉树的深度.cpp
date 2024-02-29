/*
 * @lc app=leetcode.cn id=LCR 175 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 175] 计算二叉树的深度
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
    int calculateDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(calculateDepth(root->left), calculateDepth(root->right)) + 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 2, 3, null, null, 5, 4, null, null, 4]\n
// @lcpr case=end

 */

