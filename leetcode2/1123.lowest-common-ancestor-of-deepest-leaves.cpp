/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 * @lcpr version=30204
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans = nullptr;
        int maxz = 0;
        auto post = [&](this auto&& dfs, TreeNode* node, int d) {
            if (!node) {
                maxz = max(maxz, d);
                return d;
            }
            auto ll = dfs(node->left, d + 1);
            auto rr = dfs(node->right, d + 1);
            if (ll == rr and ll == maxz) {
                ans = node;
            }
            return max(ll, rr);
        };
        post(root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,3,null,2]\n
// @lcpr case=end

 */

