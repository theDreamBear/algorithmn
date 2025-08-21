/*
 * @lc app=leetcode.cn id=99 lang=cpp
 * @lcpr version=30204
 *
 * [99] 恢复二叉搜索树
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
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
//TreeNode* TreeNode:: f[2] = {&TreeNode::left, &TreeNode:right};
class Solution {
public:
    void recoverTree1(TreeNode* root) {
        vector<TreeNode*> nodes;
        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            nodes.push_back(node);
            dfs(node->right);
        };
        in(root);
        // 插入排序
        for (int i = 1; i < nodes.size(); i++) {
            int j = i - 1;
            int val = nodes[i]->val;
            while (j >= 0 and nodes[j]->val > val) {
                nodes[j + 1]->val = nodes[j]->val;
                j--;
            }
            nodes[j + 1]->val = val;
        }
    }

    void recoverTree2(TreeNode* root) {
        vector<TreeNode*> nodes;
        auto in = [&](this auto&& dfs, TreeNode* node) {
            if (!node) return;
            dfs(node->left);
            nodes.push_back(node);
            dfs(node->right);
        };
        in(root);
        // 找大的那一个
        int x = nodes.size(), y = 0;
        for (int i = 0; i + 1 < nodes.size(); i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                x = i;
                break;
            }
        }
        // 找小的那一个
        for (int i = nodes.size() - 1; i > x; i--) {
            if (nodes[i]->val < nodes[i - 1]->val) {
                y = i;
                break;
            }
        }
        if (y > x) {
            swap(nodes[x]->val, nodes[y]->val);
        }
    }

    void recoverTree3(TreeNode* root) {
        TreeNode* x = nullptr, *y = nullptr, *pre = nullptr;

        auto in = [&](this auto&& dfs, TreeNode* node)->bool {
            if (!node or x) return x;
            if (dfs(node->left)) return true;
            if (pre and pre->val > node->val) {
                x = pre;
                return true;;
            }
            pre = node;
            return dfs(node->right);
        };
        in(root);

        pre = nullptr;
        auto in2 = [&](this auto&& dfs, TreeNode* node)->bool {
            if (!node or y) return y;
            if (dfs(node->right)) return true;
            if (pre and pre->val < node->val) {
                y = pre;
                return true;
            }
            pre = node;
            return dfs(node->left);
        };
        in2(root);

        if (x and y) {
            swap(x->val, y->val);
        }
    }

    void recoverTree4(TreeNode* root) {
        TreeNode* x = nullptr, *y = nullptr, *pre = nullptr;

        auto in = [&](this auto&& dfs, TreeNode* node){
            if (!node) return;
            dfs(node->left);
            if (pre and pre->val > node->val) {
                if (!x) x = pre;
                y = node;
            }
            pre = node;
            dfs(node->right);
        };
        in(root);
        if (x and y) {
            swap(x->val, y->val);
        }
    }

    // moris
    void recoverTree(TreeNode* root) {
        TreeNode* x = nullptr, *y = nullptr, *pre = nullptr;
        while (root) {
            if (root->left) {
                auto left = root->left;
                auto right = left;
                while (right and right->right) {
                    right = right->right;
                }
                right->right = root;
                root->left = nullptr;
                root = left;
            } else {
                // 访问 root
                if (pre and pre->val > root->val) {
                    if (!x) x = pre;
                    y = root;
                }
                pre = root;
                root = root->right;
            }
        }
        if (x and y) {
            swap(x->val, y->val);
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,null,null,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,null,null,2]\n
// @lcpr case=end

 */

