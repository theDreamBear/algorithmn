/*
 * @lc app=leetcode.cn id=563 lang=cpp
 * @lcpr version=30204
 *
 * [563] 二叉树的坡度
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
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        auto post = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            ans += abs(l - r);
            return node->val + l + r;
        };
        post(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,9,3,5,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [21,7,14,1,1,2,2,3,3]\n
// @lcpr case=end

 */

