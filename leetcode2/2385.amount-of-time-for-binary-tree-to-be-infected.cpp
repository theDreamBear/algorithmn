/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 * @lcpr version=30122
 *
 * [2385] 感染二叉树需要的总时间
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
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int amountOfTime_bad(TreeNode* root, int start) {
        function<int(TreeNode*)> height = [&](TreeNode* node) {
            if (!node) {
                return 0;
            }
            return max(height(node->left), height(node->right)) + 1;
        };
        if (root->val == start) {
            return height(root) - 1;
        }
        TreeNode* cur = nullptr;
        function<TreeNode*(TreeNode*)> deleteStart = [&](TreeNode* root)->TreeNode* {
            if (!root) {
                return nullptr;
            }
            if (root->val == start) {
                cur = root;
                return nullptr;
            }
            if (root->left and root->left->val == start) {
                cur = root->left;
                root->left = root->right = nullptr;
                return root;
            }
            if (root->right and root->right->val == start) {
                cur = root->right;
                root->left = root->right = nullptr;
                return root;
            }
            root->left = deleteStart(root->left);
            root->right = deleteStart(root->right);
            return root;
        };
        deleteStart(root);
        return max(height(root->left) + height(root->right) + 1, height(cur) - 1);
    }

    struct PTreeNode {
        TreeNode* node;
        PTreeNode* left, *right, *p;
        int visited = 0;

        PTreeNode(TreeNode* node): node(node), left(nullptr), right(nullptr), p(nullptr){}
    };

    int amountOfTime_node_with_parent(TreeNode* root, int start) {
        PTreeNode* cur = nullptr;
        function<PTreeNode*(TreeNode*)> cloneTree = [&](TreeNode* node)-> PTreeNode* {
            if (!node) {
                return nullptr;
            }
            auto child = new PTreeNode(node);
            child->left = cloneTree(node->left);
            child->right = cloneTree(node->right);
            if (child->left) {
                child->left->p = child;
            }
            if (child->right) {
                child->right->p = child;
            }
            if (child->node->val == start) {
                cur = child;
            }
            return child;
        };
        cloneTree(root);
        function<int(PTreeNode*)> dfs = [&](PTreeNode* node) {
            if (!node) {
                return 0;
            }
            if (node->visited) {
                return 0;
            }
            node->visited = 1;
            int len = 1;
            if (node->left and !node->left->visited) {
                len = max(len, dfs(node->left) + 1);
            }
            if (node->right and !node->right->visited) {
                len = max(len, dfs(node->right) + 1);
            }
            if (node->p and !node->p->visited) {
                len = max(len, dfs(node->p) + 1);
            }
            return len;
        };
        return dfs(cur) - 1;
    }

    int amountOfTime_record_parent(TreeNode* root, int start) {
        TreeNode* cur;
        unordered_map<TreeNode*, TreeNode*> parent_mp;
        unordered_map<int, int> visited;
        function<TreeNode*(TreeNode*)> cloneTree = [&](TreeNode* node)-> TreeNode* {
            if (!node) {
                return nullptr;
            }
            node->left = cloneTree(node->left);
            node->right = cloneTree(node->right);
            if (node->left) {
                parent_mp[node->left] = node;
            }
            if (node->right) {
                parent_mp[node->right] = node;
            }
            if (node->val == start) {
                cur = node;
            }
            return node;
        };
        cloneTree(root);
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) {
                return 0;
            }
            if (visited[node->val]) {
                return 0;
            }
            visited[node->val] = 1;
            int len = 1;
            if (node->left and !visited[node->left->val]) {
                len = max(len, dfs(node->left) + 1);
            }
            if (node->right and !visited[node->right->val]) {
                len = max(len, dfs(node->right) + 1);
            }
            if (parent_mp.count(node) and !visited[parent_mp[node]->val]) {
                len = max(len, dfs(parent_mp[node]) + 1);
            }
            return len;
        };
        return dfs(cur) - 1;
    }

    int amountOfTime2(TreeNode* root, int start) {
        int ans = 0;
        function<int(TreeNode*)> height = [&](TreeNode* node) {
            if (!node) {
                return 0;
            }
            int llen = height(node->left);
            int rlen = height(node->right);
            if (node->val == start) {
                ans = max({-llen, -rlen, ans});
                return 1;
            }
            if (llen > 0 || rlen > 0) {
                ans = max(abs(llen - rlen), ans);
                return llen > 0 ? llen + 1 : rlen + 1;
            }
            return min(llen, rlen) - 1;
        };
        height(root);
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        auto post = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return 0;
            int left = dfs(node->left);
            int right = dfs(node->right);
            if (node->val == start) {
                ans =  max(-min(left, right), ans);
                return 1;
            }
            if (left > 0 || right > 0) {
                ans = max(abs(left - right), ans);
                return left > 0 ? left + 1 : right + 1;
            }
            return min(left, right) - 1;
        };
        post(root);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,3,null,4,10,6,9,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

