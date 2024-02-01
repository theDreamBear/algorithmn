/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30114
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> tmp;
        /*
            循环不变量
            1、 循环开始队列有 某一层的节点且最后面多一个NULL
        */
        while (!q.empty()) {
            // 最开始是第一层
            auto node = q.front();
            q.pop();
            if (node) {
                tmp.push_back(node->val);
                // 如果节点有子节点将子节点放入队列
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            } else {
                // 读到空节点表示上一层已经完成出队列， 目前队列只剩下下一层的值
                ans.push_back(tmp);
                tmp.clear();
                // 如果下一层不为空， 则在末尾加上NULL, 维持循环不变量
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& ans, TreeNode* node, int depth) {
        if (!node) {
            return;
        }
        if (depth >= ans.size()) {
            ans.resize(depth + 1);
        }
        ans[depth].push_back(node->val);
        dfs(ans, node->left, depth + 1);
        dfs(ans, node->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        dfs(ans, root, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

