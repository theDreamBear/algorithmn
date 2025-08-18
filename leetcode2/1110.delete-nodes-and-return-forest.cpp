/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 * @lcpr version=30204
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toD(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;

        auto post = [&](this auto&& dfs, TreeNode* node)->TreeNode* {
            if (!node) return nullptr;
            node->left = dfs(node->left);
            node->right = dfs(node->right);
            if (toD.count(node->val)) {
                if (node->left) {
                    ans.push_back(node->left);
                }
                if (node->right) {
                    ans.push_back(node->right);
                }
                return nullptr;
            }
            return node;
        };
        auto x = post(root);
        if (x) ans.push_back(x);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n[3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,null,3]\n[3]\n
// @lcpr case=end

 */

