/*
 * @lc app=leetcode.cn id=2471 lang=cpp
 * @lcpr version=30204
 *
 * [2471] 逐层排序二叉树所需的最少操作数目
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
#include <map>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
struct TreeNode {
    int       val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
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
    int minimumOperations_sort(TreeNode* root) {
        // 逆序对和交换有啥关系呢?
        // 层次遍历
        queue<TreeNode*> q;
        q.push(root);
        int         ans = 0;
        vector<int> vals;
        while (!q.empty()) {
            vals.clear();
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            //
            // 每个值对应的位置
            map<int, int> pos;
            for (int i = 0; i < vals.size(); i++) {
                pos[vals[i]] = i;
            }
            for (int i = 0; i < vals.size(); i++) {
                if (pos.begin()->second == i) {
                    pos.erase(pos.begin());
                    continue;
                }
                ++ans;
                // 修正
                int badval = vals[i], badpos = i;
                int val = pos.begin()->first, p = pos.begin()->second;
                // 删除首
                pos.erase(pos.begin());
                // 覆盖
                pos[badval] = p;
                vals[p]     = badval;
            }
        }
        return ans;
    }

    // 置换环
    int minimumOperations(TreeNode* root) {
        // 逆序对和交换有啥关系呢?
        // 层次遍历
        queue<TreeNode*> q;
        q.push(root);
        int         ans = 0;
        vector<int> vals;
        while (!q.empty()) {
            vals.clear();
            int sz = q.size();
            while (sz--) {
                auto node = q.front();
                q.pop();
                vals.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            int n = vals.size();
            auto b = vals;
            ranges::sort(b);
            for (int i = 0; i < n; i++) {
                vals[i] = lower_bound(b.begin(), b.end(), vals[i]) - b.begin();
            }
            vector<int> id(n);

            auto dfs = [&](auto&& dfs, int u)->int {
                id[u] = 1;
                int res = 1;
                if (!id[vals[u]]) {
                    res += dfs(dfs, vals[u]);
                }
                return res;
            };
            for (int i = 0; i < n; i++) {
                if (!id[i]) {
                    ans += (dfs(dfs, i) - 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,7,6,8,5,null,null,null,null,9,null,10]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,7,6,5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6]\n
// @lcpr case=end

 */
