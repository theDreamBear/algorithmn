/*
 * @lc app=leetcode.cn id=LCR 043 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 043] 完全二叉树插入器
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
class CBTInserter1 {
private:
    queue<TreeNode*> candidate;
    queue<TreeNode*> next;
    TreeNode* r;

public:
    CBTInserter1(TreeNode* root) {
        r = root;
        candidate.push(root);
        while (!candidate.empty()) {
            int sz = candidate.size();
            while (sz-- > 0) {
                auto node = candidate.front();
                if (node->left) {
                    next.push(node->left);
                } else {
                    break;
                }
                if (node->right) {
                    next.push(node->right);
                } else {
                    break;
                }
                candidate.pop();
            }
            if (candidate.empty()) {
                candidate = next;
                next = {};
            } else {
                break;
            }
        }
    }

    int insert(int v) {
        auto node = new TreeNode(v);
        int n = next.size();
        int idx = n >> 1;
        int mod = n % 2;
        auto p = candidate.front();
        int ans = p->val;
        if (mod == 0) {
            p->left = node;
        } else {
            p->right = node;
            candidate.pop();
        }
        next.push(node);
        if (candidate.empty()) {
            candidate = next;
            next = {};
        }
        return ans;
    }

    TreeNode* get_root() {
        return r;
    }
};

class CBTInserter {
private:
    queue<TreeNode*> candidate;
    TreeNode* r;

public:
    CBTInserter(TreeNode* root) {
        r = root;
        candidate.push(root);
        while (!candidate.empty()) {
            auto node = candidate.front();
            if (!node->left) {
                break;
            }
            candidate.push(node->left);
            if (!node->right) {
                break;
            }
            candidate.push(node->right);
            candidate.pop();
        }
    }

    int insert(int v) {
        auto child = new TreeNode(v);
        auto node = candidate.front();
        int ans = node->val;
        if (!node->left) {
            node->left = child;
        } else {
            node->right = child;
            candidate.pop();
        }
        candidate.push(child);
        return ans;
    }

    TreeNode* get_root() {
        return r;
    }
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end



/*
// @lcpr case=start
// ["CBTInserter","insert","get_root"]\n[[[1]],[2],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["CBTInserter","insert","insert","get_root"]\n[[[1,2,3,4,5,6]],[7],[8],[]]\n
// @lcpr case=end

 */

