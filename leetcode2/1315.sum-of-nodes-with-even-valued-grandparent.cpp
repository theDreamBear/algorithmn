/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 * @lcpr version=30204
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int sumEvenGrandparent1(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> fa;
        int ans = 0;

        auto pre = [&](this auto&& dfs, TreeNode* node, TreeNode* p) {
            if (!node) return;
            if (p) {
                fa[node] = p;
            }
            if (p and fa.count(p) and fa[p]->val % 2 == 0) {
                ans += node->val;
            }
            dfs(node->left, node);
            dfs(node->right, node);
        };

        pre(root, nullptr);
        return ans;
    }

    int sumEvenGrandparent(TreeNode* root) {
        int ans = 0;

        auto add = [&](TreeNode* node) {
            if (!node) return;
            if (node->left) {
                ans += node->left->val;
            }
            if (node->right) {
                ans += node->right->val;
            }
        };

        auto pre = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            if (node->val % 2 == 0) {
                add(node->left);
                add(node->right);
            }
            dfs(node->left);
            dfs(node->right);
        };

        pre(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]\n
// @lcpr case=end

 */

