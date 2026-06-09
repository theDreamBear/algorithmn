/*
 * @lc app=leetcode.cn id=面试题 04.10 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.10] 检查子树
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
    bool checkSubTree1(TreeNode* t1, TreeNode* t2) {
        /// (1_())
        auto dfs = [&](auto&& dfs, TreeNode* node)->string {
            if (!node) {
                return "()";
            }
            string root = to_string(node->val);
            root += dfs(dfs, node->left);
            root += dfs(dfs, node->right);
            return "(" + root + ")";
        };
        auto st1 = dfs(dfs, t1);
        auto st2 = dfs(dfs, t2);
        return strstr(st1.c_str(), st2.c_str());
    }

    bool checkSubTree2(TreeNode* t1, TreeNode* t2) {
        if (!t2) return true;
        // 统计每个节点的高度和子节点个数
        unordered_map<TreeNode*, int> h, ct;
        auto stat = [&](auto&& dfs, TreeNode* node)->pair<int, int> {
            if (!node) {
                return {0, 0};
            }
            auto [lh, lc] = dfs(dfs, node->left);
            auto [rh, rc] = dfs(dfs, node->right);
            h[node] = max(lh, rh) + 1;
            ct[node] = lc + rc + 1;
            return {h[node], ct[node]};
        };
        stat(stat, t1);
        stat(stat, t2);

        auto check = [&](auto&& dfs, TreeNode* l, TreeNode* r) {
            if (!l and !r) return true;
            if (!l or !r) return false;
            if (l->val != r->val or h[l] != h[r] or ct[l] != ct[r]) return false;
            return dfs(dfs, l->left, r->left) and dfs(dfs, l->right, r->right);
        };

        auto dfs = [&](auto&& dfs, TreeNode* node) {
            if (!node or ct[node] < ct[t2]) return false;
            if (node->val == t2->val and h[node] == h[t2] and ct[node] == ct[t2] and check(check, node, t2)) {
                return true;
            }
            if (dfs(dfs, node->left) or dfs(dfs, node->right)) return true;
            return false;
        };
        return dfs(dfs, t1);
    }

    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        auto gh = [&](auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            return max(dfs(dfs, node->left), dfs(dfs, node->right)) + 1;
        };
        int hs = gh(gh, t2);

        auto isSameTree = [&](auto&& dfs, TreeNode* l, TreeNode* r) {
            if (!l and !r) return true;
            if (!l or !r) return false;
            if (l->val != r->val) return false;
            return dfs(dfs, l->left, r->left) and dfs(dfs, l->right, r->right);
        };

        // 整数 层数
        // 负数 找到了
        auto dfs = [&](auto&& dfs, TreeNode* node)-> int {
            if (!node) return 0;
            int lx = dfs(dfs, node->left);
            int rx = dfs(dfs, node->right);
            if (lx < 0 or rx < 0) return -1;
            int ans = max(lx, rx) + 1;
            if (ans == hs and isSameTree(isSameTree,node, t2)) {
                return -1;
            }
            return ans;
        };
        return dfs(dfs, t1) < 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1, null, 2, 4]\n[3, 2]\n
// @lcpr case=end

 */

