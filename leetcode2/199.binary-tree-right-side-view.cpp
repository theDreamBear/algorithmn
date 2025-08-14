/*
 * @lc app=leetcode.cn id=199 lang=cpp
 * @lcpr version=30204
 *
 * [199] 二叉树的右视图
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
    // 中 右 左
    vector<int> rightSideView1(TreeNode* root) {
        if (!root) return {};
        vector<int> ans(100, -10000);
        auto pre = [&](this auto&& dfs, TreeNode* node, int depth) {
            if (!node) return;
            if (ans[depth] == -10000) ans[depth] = node->val;
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        };
        pre(root, 0);
        auto size = find(ans.begin(), ans.end(), -10000) - ans.begin();
        ans.resize(size);
        return ans;
    }

        // 中 右 左
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        auto pre = [&](this auto&& dfs, TreeNode* node, int depth) {
            if (!node) return;
            if (depth >= ans.size()) {
                ans.push_back(node->val);
            }
            dfs(node->right, depth + 1);
            dfs(node->left, depth + 1);
        };
        pre(root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,null,5,null,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

