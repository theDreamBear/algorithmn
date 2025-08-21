/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 * @lcpr version=30204
 *
 * [2476] 二叉搜索树最近节点查询
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
    vector<int> a;

    void dfs(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        dfs(node->left);
        a.push_back(node->val);
        dfs(node->right);
    };

public:
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
        dfs(root);
        int n = a.size();
        vector<vector<int>> ans;
        for (int q : queries) {
            int j = ranges::lower_bound(a, q) - a.begin();
            int mx = j < n ? a[j] : -1;
            if (j == n || a[j] != q) { // a[j]>q, a[j-1]<q
                j--;
            }
            int mn = j >= 0 ? a[j] : -1;
            ans.push_back({mn, mx});
        }
        return ans;
    }
};

class Solution1 {
public:
    // 傻乎乎的, 直接存二分就可以了
     vector<vector<int>> closestNodes1(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans(queries.size(), {-1, -1});
        vector<pair<int, int>> q(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            q[i] = {queries[i], i};
        }
        ranges::sort(q);
        int pre = -1;
        int i = 0;

        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node or i >= q.size()) return;

            dfs(node->left);

            // 逐个匹配
            while (i < q.size()) {
                if (node->val == q[i].first) {
                    ans[q[i++].second] = {node->val, node->val};
                } else if (pre < q[i].first and q[i].first < node->val) {
                    ans[q[i].second] = {pre, node->val};
                    i++;
                } else {
                    break;
                }
            }
            pre = node->val;

            dfs(node->right);
        };
        in(root);
        // 没有计算的设置左值
        for (; i < q.size(); i++) {
            ans[q[i].second][0] = pre;
        }
        return ans;
    }

    // 超时
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans(queries.size());


        auto qm = [&](this auto&& dfs, TreeNode* node, int val) {
            int pr = -1;
            while (node) {
                if (node->val == val) {
                    return val;
                }
                if (node->val < val) {
                    pr = node->val;
                    node = node->right;
                } else {
                    node = node->left;
                }
            }
            return pr;
        };

        auto qx = [&](this auto&& dfs, TreeNode* node, int val) {
            int pr = -1;
            while (node) {
                if (node->val == val) {
                    return val;
                }
                if (node->val > val) {
                    pr = node->val;
                    node = node->left;
                } else {
                    node = node->right;
                }
            }
            return pr;
        };
        int i = 0;
        for (auto v: queries) {
            ans[i++] = {qm(root, v), qx(root, v)};
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,13,1,4,9,15,null,null,null,null,null,null,14]\n[2,5,16]\n
// @lcpr case=end

// @lcpr case=start
// [4,null,9]\n[3]\n
// @lcpr case=end

 */

