/*
 * @lc app=leetcode.cn id=3319 lang=cpp
 * @lcpr version=30204
 *
 * [3319] 第 K 大的完美二叉子树的大小
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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> res;
        
        auto dfs = [&](auto&& dfs, TreeNode* node)->pair<bool, int> {
            if (!node) return {true, 0};
            auto left =  dfs(dfs, node->left);
            auto right = dfs(dfs, node->right);
            if (left == right and left.first) {
                res.push_back(left.second + right.second + 1);
                return {true, left.second + right.second + 1};
            }
            return {false, left.second + right.second + 1};
        };
        dfs(dfs, root);
        ranges::sort(res, greater<>{});
        if (k > res.size()) return -1;
        return res[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,5,2,5,7,1,8,null,null,6,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,null,4]\n3\n
// @lcpr case=end

 */

