/*
 * @lc app=leetcode.cn id=872 lang=cpp
 * @lcpr version=30204
 *
 * [872] 叶子相似的树
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
    bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
        auto get = [&](auto&& get, TreeNode* node, vector<int>& ans) {
            if (!node) {
                return;
            }
            if (!node->left and !node->right) {
                ans.push_back(node->val);
            }
            get(get, node->left, ans);
            get(get, node->right, ans);
        };
        vector<int> left, right;
        get(get, root1, left);
        get(get, root2, right);
        return left == right;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto gen = [](TreeNode* node) {
            stack<TreeNode*> st;
            while (node) {
                st.push(node);
                node = node->left;
            }
            return [st]() mutable ->TreeNode* {
                if (st.empty()) return nullptr;
                while (!st.empty()) {
                    auto nd = st.top();
                    st.pop();
                    // 找到了页节点
                    if (!nd->left and !nd->right) {
                        return nd;
                    }
                    nd = nd->right;
                    while (nd) {
                        st.push(nd);
                        nd = nd->left;
                    }
                }
                return nullptr;
            };
        };
        auto g1 = gen(root1), g2 = gen(root2);
        TreeNode* left, *right;
        while (1) {
            left = g1();
            right = g2();
            if (!left and !right ) break;
            if (!left or !right) return false;
            if (left->val != right->val) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n[1,3,2]\n
// @lcpr case=end

 */

