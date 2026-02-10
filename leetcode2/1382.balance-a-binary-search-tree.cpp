/*
 * @lc app=leetcode.cn id=1382 lang=cpp
 * @lcpr version=30204
 *
 * [1382] 将二叉搜索树变平衡
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;

        auto getall = [&](auto&& dfs, TreeNode* node) {
            if (!node) return;
            if (node->left) dfs(dfs, node->left);
            nodes.push_back(node);
            if (node->right) dfs(dfs, node->right);
        };

        getall(getall, root);

        auto make = [&](auto&& dfs, int low, int high)->TreeNode* {
            if (low > high) return nullptr;
            int mid = (low + high) / 2;
            auto node = nodes[mid];
            node->left = dfs(dfs, low, mid - 1);
            node->right = dfs(dfs, mid + 1, high);
            return node;
        };
        return make(make, 0, nodes.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,null,3,null,4,null,null]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

 */

