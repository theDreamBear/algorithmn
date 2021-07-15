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

    void findPath1(unordered_map<TreeNode *, int> &path, TreeNode *root, TreeNode *target) {
        int v = 0;
        TreeNode *cur = root;
        while (true) {
            path[cur] = v++;
            if (canVisit(cur->left, target)) {
                cur = cur->left;
            } else if (canVisit(cur->right, target)) {
                cur = cur->right;
            } else {
                break;
            }
        }
    }

    void findPathHelper(TreeNode *node, TreeNode *target, string track, string &res) {
        if (!node) {
            return;
        }
        if (node == target) {
            res = track;
            return;
        }
        track.push_back('0');
        findPathHelper(node->left, target, track, res);
        track.pop_back();
        if (res == "") {
            track.push_back('1');
            findPathHelper(node->right, target, track, res);
        }
    }

    void findPath(unordered_map<TreeNode *, int> &path, TreeNode *root, TreeNode *target) {
        string r;
        findPathHelper(root, target, "", r);
        int v = 0;
        TreeNode *cur = root;
        path[cur] = v++;
        for (auto &c : r) {
            if (c == '0') {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
            path[cur] = v++;
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

    vector<int> distanceK1(TreeNode *root, TreeNode *target, int k) {
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

    void sub_add(vector<int> &ans, TreeNode *node, int cur, int K) {
        if (!node) {
            return;
        }
        if (cur == K) {
            ans.push_back(node->val);
        }
        sub_add(ans, node->left, cur + 1, K);
        sub_add(ans, node->right, cur + 1, K);
    }

    int dfs(vector<int> &ans, TreeNode *node, TreeNode *target, int K) {
        if (!node) {
            return -1;
        }
        if (node == target) {
            sub_add(ans, node, 0, K);
            return 1;
        } else {
            int L = dfs(ans, node->left, target, K);
            int R = dfs(ans, node->right, target, K);
            if (L != -1) {
                if (L == K) {
                    ans.push_back(node->val);

                } else {
                    sub_add(ans, node->right, L + 1, K);
                }
                return L + 1;
            } else if (R != -1) {
                if (R == K) {
                    ans.push_back(node->val);
                } else {
                    sub_add(ans, node->left, R + 1, K);
                }
                return R + 1;
            }
            return -1;
        }
    }

    vector<int> distanceK3(TreeNode *root, TreeNode *target, int k) {
        vector<int> ans;
        dfs(ans, root, target, k);
        return ans;
    }

    void preOrderTraversal(TreeNode* node, TreeNode* father, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) {
            return;
        }
        parent[node] = father;
        preOrderTraversal(node->left, node, parent);
        preOrderTraversal(node->right, node, parent);
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        preOrderTraversal(root, NULL, parent);
        // bfs
        queue<TreeNode*> q;
        unordered_set<TreeNode*> seen;
        q.push(target);
        seen.insert(target);
        int dist = -1;
        while (!q.empty()) {
            dist++;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                // 左
                auto node = q.front();
                q.pop();
                if (dist == k) {
                    ans.push_back(node->val);
                }
                if (node->left && seen.count(node->left) == 0) {
                    seen.insert(node->left);
                    if (dist < k) {
                        q.push(node->left);
                    }
                }
                // 右
                if (node->right && seen.count(node->right) == 0) {
                    seen.insert(node->right);
                    if (dist < k) {
                        q.push(node->right);
                    }
                }
                // 父
                auto father = parent[node];
                if (father && seen.count(father) == 0) {
                    seen.insert(father);
                    if (dist < k) {
                        q.push(father);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

