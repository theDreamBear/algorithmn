/*
 * @lc app=leetcode.cn id=94 lang=cpp
 * @lcpr version=30114
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return;
            }
            dfs(node->left);
            ans.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }

    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> q;
        TreeNode*        cur = root;
        while (cur || !q.empty()) {
            while (cur) {
                q.push(cur);
                cur = cur->left;
            }
            cur = q.top();
            q.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }

    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        stack<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.top();
            if (node->val < 9000 and node->left) {
                node->val += 10000;
                q.push(node->left);
            } else {
                if (node->val > 9000) {
                    node->val -= 10000;
                }
                ans.push_back(node->val);
                q.pop();
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        // 定义: 1.q 内所有节点的左节点已经加入到队列
        // 定义: 2.q 内没有空节点
        stack<TreeNode*> q;
        TreeNode* node = root;
        while (node) {
            q.push(node);
            node = node->left;
        }
        while (!q.empty()) {
            node = q.top();
            q.pop();
            ans.push_back(node->val);
            if (node->right) {
                node = node->right;
                while (node) {
                    q.push(node);
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

 */
