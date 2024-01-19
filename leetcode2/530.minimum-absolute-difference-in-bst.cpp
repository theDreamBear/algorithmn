/*
 * @lc app=leetcode.cn id=530 lang=cpp
 * @lcpr version=30113
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference1(TreeNode* root) {
        // 中序遍历， 非递归
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        int ans = 1e6;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre) {
                ans = min(ans, cur->val - pre->val);
            }
            pre = cur;
            cur = cur->right;
        }
        return ans;
    }

    // 数据量不大, 先存起来再操作
    int getMinimumDifference2(TreeNode* root) {
        // 中序遍历
        vector<int> data;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            data.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        int ans = 1e6;
        for (int i = 1; i < data.size(); i++) {
            ans = min(ans, data[i] - data[i - 1]);
        }
        return ans;
    }

    int getMinimumDifference(TreeNode* root) {
        // 中序遍历
        TreeNode* pre = NULL;
        int ans = 1e6;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            if (pre) {
                ans = min(ans, node->val - pre->val);
            }
            pre = node;
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,6,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,48,null,null,12,49]\n
// @lcpr case=end

 */

