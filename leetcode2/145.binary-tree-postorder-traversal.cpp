/*
 * @lc app=leetcode.cn id=145 lang=cpp
 * @lcpr version=30204
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> ans;

        auto dfs = [&](this auto& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            dfs(node->right);
            ans.push_back(node->val);
        };

        dfs(root);
        return ans;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;

        TreeNode* pre = nullptr;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            // 右边已经遍历完了
            if (!cur->right or cur->right == pre) {
                ans.push_back(cur->val);
                // 更新上一个节点
                pre = cur;
                st.pop();
                cur = nullptr;
            } else {
                cur = cur->right;
            }
        }
        return ans;
    }

    vector<int> postorderTraversal3(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans;

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.emplace_back(node->val);
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> ans;
        unordered_map<TreeNode*, int> cnt;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            auto node = st.top();
            cnt[node]++;
            if (!node->right or cnt[node->right]) {
                ans.push_back(node->val);
                st.pop();
                continue;
            }
            cur = node->right;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,null,8,null,null,6,7,9]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

