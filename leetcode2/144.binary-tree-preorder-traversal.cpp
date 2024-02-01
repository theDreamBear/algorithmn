/*
 * @lc app=leetcode.cn id=144 lang=cpp
 * @lcpr version=30114
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (nullptr == node) {
                return;
            }
            ans.push_back(node->val);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }

    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                ans.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
        }
        return ans;
    }

    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        return ans;
    }

     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }
        stack<TreeNode*> st;
        auto node = root;
        while (node) {
            ans.push_back(node->val);
            st.push(node);
            node = node->left;
        }
        while (!st.empty()) {
            node = st.top();
            st.pop();
            if (node->right) {
                node = node->right;
                while (node) {
                    ans.push_back(node->val);
                    st.push(node);
                    node = node->left;
                }
            }
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
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

