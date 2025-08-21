/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 * @lcpr version=30204
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
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
     string getDirections2(TreeNode* root, int startValue, int destValue) {
        auto findAc = [&](this auto&& dfs, TreeNode* node) {
            if (!node || node->val == startValue || node->val == destValue) return node;
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            if (left and right) return node;
            return left ? left : right;
        };
        // 找公共祖先
        auto node = findAc(root);
        return "";
    }

    // 过了
    string getDirections(TreeNode* root, int startValue, int destValue) {

        auto findAc = [&](this auto&& dfs, TreeNode* node) {
            if (!node || node->val == startValue || node->val == destValue) return node;
            auto left = dfs(node->left);
            auto right = dfs(node->right);
            if (left and right) return node;
            return left ? left : right;
        };

        // 找公共祖先
        auto node = findAc(root);
        string left;
        string right;
        auto find = [&](this auto&& dfs, TreeNode* node, string& path, int target, int depth) {
            if (!node) {
                return 0;
            }
            if (node->val == target) {
                //right = path;
                return depth;
            }
            path.push_back('L');
            int left = dfs(node->left, path, target, depth + 1);
            if (left) {
                return left;
            }
            path.pop_back();

            path.push_back('R');
            int right = dfs(node->right, path, target, depth + 1);
            if (right) {
                return right;
            }
            path.pop_back();
            return 0;
        };
        int rh = find(node, left, destValue, 1);

        right.clear();
        int lh = find(node, right, startValue, 1);
        string ls(lh - 1, 'U');
        return ls + left;
    }

    // 内存超了
    // 逻辑反而复杂了
    string getDirections1(TreeNode* root, int startValue, int destValue) {
        // int, 0 没找到, 1 找到 s, -1 找到 t, 2 找到了
        // type 0 左, 1 右
        auto post = [&](this auto&& dfs, TreeNode* node, int type)->pair<int, string> {
            // 边界
            if (!node) {
                return {0, ""};
            }
            auto [li, ls] = dfs(node->left, 0);
            auto [ri, rs] = dfs(node->right, 1);

            if (li == 2) return {li, ls};
            if (ri == 2) return {ri, rs};

            if (li * ri == -1) {
                if (li == 1) {
                    reverse(rs.begin(), rs.end());
                    return {2, ls + rs};
                }
                reverse(ls.begin(), ls.end());
                return {2, rs + ls};
            }

            if (li == 1) {
                if (node->val == destValue) {
                    return {2, ls};
                }
                // 向上
                ls.push_back('U');
                return {li, ls};
            }

            if (ri == 1) {
                if (node->val == destValue) {
                    return {2, rs};
                }
                // 向上
                rs.push_back('U');
                return {ri, rs};
            }

            if (li == -1) {
                if (node->val == startValue) {
                    reverse(ls.begin(), ls.end());
                    return {2, ls};
                }
                auto res = type == 0 ? 'L' : 'R';
                ls.push_back(res);
                return {li, ls};
            }

            if (ri == -1) {
                if (node->val == startValue) {
                    reverse(rs.begin(), rs.end());
                    return {2, rs};
                }
                auto res = type == 0 ? 'L' : 'R';
                rs.push_back(res);
                return {ri, rs};
            }

            if (node->val == startValue) {
                return {1, "U"};
            }

            if (node->val == destValue) {
                string res = type == 0 ? "L" : "R";
                return {-1, res};
            }
            return {};
        };
        return post(root, -1).second;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,1,2,3,null,6,4]\n3\n6\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n1\n
// @lcpr case=end

 */

