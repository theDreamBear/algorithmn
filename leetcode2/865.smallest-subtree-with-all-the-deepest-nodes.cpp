/*
 * @lc app=leetcode.cn id=865 lang=cpp
 * @lcpr version=30204
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        int maxd = -1;
        TreeNode* ans = nullptr;

        auto post = [&](this auto&& dfs, TreeNode* node, int depth)->int {
            if (!node) {
                maxd = max(maxd, depth);
                return depth;
            }
            auto left = dfs(node->left, depth + 1);
            auto right = dfs(node->right, depth + 1);
            if (left == right and left == maxd) {
                ans = node;
            }
            return max(left, right);
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

