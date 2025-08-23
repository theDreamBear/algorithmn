/*
 * @lc app=leetcode.cn id=1932 lang=cpp
 * @lcpr version=30204
 *
 * [1932] 合并多棵二叉搜索树
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
    TreeNode* canMerge1(vector<TreeNode*>& trees) {
        unordered_map<int, int> roots;
        for (int i = 0; i < trees.size(); i++) roots[trees[i]->val] = i;

        vector<int> fa(trees.size());
        iota(fa.begin(), fa.end(), 0);

        auto find = [&](this auto&& dfs, int u)->int {
            if (fa[u] == u) return u;
            return fa[u] = dfs(fa[u]);
        };

        auto merge = [&](int u, int v) {
            int pu = find(u), pv = find(v);
            if (pu == pv) return;
            if (pu < pv) {
                fa[pv] = pu;
            } else {
                fa[pu] = pv;
            }
        };

        for (int i = 0; i < trees.size(); i++) {
            auto pre = [&](this auto&& dfs, TreeNode* node) {
                if (!node) return;
                if (!node->left and !node->right) {
                    if (roots.count(node->val)) {
                        int idx = roots[node->val];
                        if (find(i) != find(idx)) {
                            // 找到了一个
                            node->left = trees[idx]->left;
                            node->right = trees[idx]->right;
                            trees[idx] = node;
                            roots.erase(node->val);
                            merge(i, idx);
                        }
                    }
                    return;
                }
                dfs(node->left);
                dfs(node->right);
            };
            pre(trees[i]);
        }

        if (roots.size() != 1) return {};
        auto head = trees[roots.begin()->second];

        int pre = -1;
        auto Is = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return true;
            if (!dfs(node->left)) {
                return false;
            }
            if (pre >= node->val) return false;
            pre = node->val;
            return dfs(node->right);
        };
        if (Is(head)) return head;
        return {};
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> roots;
        unordered_set<int> leaves;
        for (auto& r: trees) {
            if (r->left) {
                if (leaves.count(r->left->val)) return nullptr;
                leaves.insert(r->left->val);
            }
            if (r->right) {
                if (leaves.count(r->right->val)) return nullptr;
                leaves.insert(r->right->val);
            }
            roots[r->val] = r;
        }

        TreeNode* root = nullptr;
        for (auto r: trees) {
            if (!leaves.count(r->val)) {
                if (root) return nullptr;
                root = r;
            }
        }
        if (!root) return nullptr;

        auto build = [&](this auto&& dfs, TreeNode* node, int mm = INT_MIN, int mx = INT_MAX) {
            if (!node) return true;
            if (node->val <= mm or node->val >= mx) return false;
            if (!node->left and !node->right) {
                if (!roots.count(node->val) or roots[node->val] == node) {
                    return true;
                }
                 // 拼接
                node->left = roots[node->val]->left;
                node->right = roots[node->val]->right;
                roots.erase(node->val);
            }
            return dfs(node->left, mm, node->val) and dfs(node->right, node->val, mx);
        };

        //return  build(root) and roots.size() == 1 ? root : nullptr;

        int cnt = 0;
        auto build2 = [&](this auto&& dfs, TreeNode* node, int mm = INT_MIN, int mx = INT_MAX)->TreeNode* {
            if (!node) return nullptr;
            ++cnt;
            if (node->left) {
                if (node->left->val <= mm) return nullptr;
                if (roots.count(node->left->val)) {
                    node->left = dfs(roots[node->left->val], mm, node->val);
                    if (!node->left) return nullptr;
                }
            }

            if (node->right) {
                if (node->right->val >= mx) return nullptr;
                if (roots.count(node->right->val)) {
                    node->right = dfs(roots[node->right->val], node->val, mx);
                    if (!node->right) return nullptr;
                }
            }
            return node;
        };
        return  build2(root) and cnt == trees.size() ? root : nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1],[3,2,5],[5,4]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,3,8],[3,2,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,4],[3]]\n
// @lcpr case=end

 */

