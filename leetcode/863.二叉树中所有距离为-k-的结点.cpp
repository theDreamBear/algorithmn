/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool canVisit(TreeNode *root, TreeNode *target) {
        if (!root) {
            return false;
        }
        if (root == target) {
            return true;
        }
        if (canVisit(root->left, target)) {
            return true;
        }
        return canVisit(root->right, target);
    }

    void findPath(unordered_map<TreeNode *, int> &path, TreeNode *root, TreeNode *target) {
        int v = 0;
        TreeNode *cur = root;
        while (true) {
            path[cur] = v++;
            if (canVisit(cur->left, target)) {
               cur = cur->left;
            } else if(canVisit(cur->right, target)) {
                cur = cur->right;
            } else {
                break;
            }
        }
    }

    void visit(unordered_map<TreeNode *, int> &hash, TreeNode *node, int v, int step) {
        if (!node) {
            return;
        }
        hash[node] = v;
        visit(hash, node->left, v + step, step);
        visit(hash, node->right, v + step, step);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        vector<int> ans;
        unordered_map<TreeNode *, int> path;
        findPath(path, root, target);
        int v = path[target];
        for (auto &kv : path) {
            if (abs(kv.second - v) == k) {
                ans.push_back(kv.first->val);
            }
            int step = 1;
            unordered_map<TreeNode *, int> hash;
            if (kv.second >= v) {
                visit(hash, kv.first->left, kv.second + step, step);
                visit(hash, kv.first->right, kv.second + step, step);
            } else if (kv.second < v) {
                step = -1;
                if (path.count(kv.first->left) == 0) {
                    visit(hash, kv.first->left, kv.second + step, step);
                }
                if (path.count(kv.first->right) == 0) {
                    visit(hash, kv.first->right, kv.second + step, step);
                }
            }
            for (auto &kv1 : hash) {
                if (abs(kv1.second - v) == k) {
                    ans.push_back(kv1.first->val);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

