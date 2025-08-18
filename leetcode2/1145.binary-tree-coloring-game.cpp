/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 * @lcpr version=30204
 *
 * [1145] 二叉树着色游戏
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int ls = 0, rs = 0, ps = 0;
        bool ok = false;
        auto post = [&](this auto&& dfs, TreeNode* node) {
            if (ok) return 0;
            if (!node) return 0;
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            if (node->val == x) {
                if (node->val != root->val) {
                    ps = n - l - r - 1;
                }
                if (l > n / 2 or r > n / 2 or ps > n / 2) {
                    ok = true;
                }
            }
            return l + r + 1;
        };
        post(root);
        return ok;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10,11]\n11\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n1\n
// @lcpr case=end

 */

