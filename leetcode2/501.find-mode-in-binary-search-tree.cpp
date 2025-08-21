/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        int pre = INT_MIN;
        int cnt = 0;
        int maxcnt = 0;
        vector<int> ans;

        auto update = [&]() {
            if (cnt > maxcnt) {
                 maxcnt = cnt;
                ans.clear();
                ans.push_back(pre);
            } else if (cnt == maxcnt and cnt != 0) {
                ans.push_back(pre);
            }
        };

        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);

            if (pre == node->val) cnt++;
            else {
                update();
                cnt = 1;
                pre = node->val;
            }

            dfs(node->right);
        };
        in(root);
        update();
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

