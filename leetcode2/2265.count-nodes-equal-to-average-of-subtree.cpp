/*
 * @lc app=leetcode.cn id=2265 lang=cpp
 * @lcpr version=30204
 *
 * [2265] 统计值等于子树平均值的节点数
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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        auto p = [&](this auto&& dfs, TreeNode* node)->pair<int, int> {
            if (!node) return {0, 0};
            auto l = dfs(node->left);
            auto r = dfs(node->right);
            int sum = (l.first + r.first + node->val);
            int cnt = (l.second + r.second + 1);
            if (sum / cnt == node->val) {
                ans++;
            }
            return {sum, cnt};
        };
        p(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,8,5,0,1,null,6]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

