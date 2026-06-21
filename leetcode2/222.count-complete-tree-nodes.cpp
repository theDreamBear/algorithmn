/*
 * @lc app=leetcode.cn id=222 lang=cpp
 * @lcpr version=30204
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes1(TreeNode* root) {
        int ans = 0;
        auto pre = [&](auto&& dfs, TreeNode* node) {
            if (!node) return;
            ans++;
            dfs(dfs, node->left);
            dfs(dfs, node->right);
        };
        pre(pre, root);
        return ans;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        auto height = [&](TreeNode* node) {
            int ans = 0;
            while (node) {
                ans++;
                node = node->left;
            }
            return ans;
        };
        int h = height(root);
        int low = pow(2, h - 1), high = pow(2, h) - 1;
        auto check = [&](int cnt) {
            TreeNode* node = root;
            for (int i = h - 2; i >= 0; i--) {
                if (!(cnt & (1 << i))) {
                    node = node->left;
                } else {
                    node = node->right;
                }
                if (!node) return false;
            }
            return true;
        };
        while (low + 1 < high) {
            int mid = (low + high) >> 1;
            if (check(mid)) {
                low = mid;
            } else high = mid;
        }
        if (check(high)) return high;
        return low;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

