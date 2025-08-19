/*
 * @lc app=leetcode.cn id=538 lang=cpp
 * @lcpr version=30204
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        int sum = 0;
        auto add = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            sum += node->val;
            dfs(node->left);
            dfs(node->right);
        };
        add(root);
        int val = 0;
        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            int nv = sum - val;
            val += node->val;
            node->val = nv;
            dfs(node->right);
        };
        in(root);
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]\n
// @lcpr case=end

// @lcpr case=start
// [0,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4,1]\n
// @lcpr case=end

 */

