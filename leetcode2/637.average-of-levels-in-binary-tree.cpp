/*
 * @lc app=leetcode.cn id=637 lang=cpp
 * @lcpr version=30113
 *
 * [637] 二叉树的层平均值
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <assert.h>
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
#define ID (i % 2)
#define PID ((i + 1) % 2)
#define cur_que (q[ID])
#define next_que (q[PID])
#define exchange_que() (i = (i + 1) % 2);
#define init_var() \
    cur = 0;      \
    ct  = cur_que.size();

class Solution {
  public:
    vector<double> averageOfLevels_1(TreeNode* root) {
        if (!root) {
            assert("node is NULL");
        }
        vector<double> ans;
        queue<TreeNode*> q[2];
        int              i = -1;

        // 第一层入队列
        double ct = 0;
        next_que.push(root);
        ct++;
        i++;
        // 每一层的结果在入队列的时候进行计算
        ans.push_back(root->val / ct);

        while (!cur_que.empty()) {
            long long cur = 0;
            double    ct  = 0;
            while (!cur_que.empty()) {
                auto node = cur_que.front();
                if (!node) {
                    assert("node is NULL");
                }
                if (node->left) {
                    next_que.push(node->left);
                    cur += node->left->val;
                    ct++;
                }
                if (node->right) {
                    next_que.push(node->right);
                    cur += node->right->val;
                    ct++;
                }
                cur_que.pop();
            }
            if (ct) {
                ans.push_back(cur / ct);
            }
            i++;
        }
        return ans;
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) {
            assert("node is NULL");
        }
        vector<double> ans;
        queue<TreeNode*> q[2];
        // 初始化
        int i = 0;
        cur_que.push(root);
        long long cur;
        double    ct;
        init_var();
        // 每一层的结果在入队列的时候进行计算
        while (!cur_que.empty()) {
            auto node = cur_que.front();
            if (!node) {
                assert("node is NULL");
            }
            cur += node->val;
            if (node->left) {
                next_que.push(node->left);
            }
            if (node->right) {
                next_que.push(node->right);
            }
            cur_que.pop();
            if (cur_que.empty()) {
                ans.push_back(cur / ct);
                exchange_que();
                init_var();
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [3,9,20,15,7]\n
// @lcpr case=end

 */
