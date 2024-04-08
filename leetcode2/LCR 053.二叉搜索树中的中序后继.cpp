/*
 * @lc app=leetcode.cn id=LCR 053 lang=cpp
 * @lcpr version=30121
 *
 * [LCR 053] 二叉搜索树中的中序后继
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;

public:
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* lp, TreeNode* p) {
        // 找到节点p值相同的节点
        if (root->val < p->val) {
            parent[root->right] = lp;
            return inorderSuccessor(root->right, lp, p);
        }
        if (root->val > p->val) {
            parent[root->left] = root;
            return inorderSuccessor(root->left, root, p);
        }
        TreeNode* cur = root->right;
        TreeNode* pre = NULL;
        while (cur) {
            pre = cur;
            cur = cur->left;
        }
        return pre ? pre : parent[root];
    }

    TreeNode* inorderSuccessor1(TreeNode* root, TreeNode* p) {
        return inorderSuccessor(root, NULL, p);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = nullptr;
        if (p->right) {
           successor = p->right;
            while (successor->left) {
                successor = successor->left;
            }
            return successor;
        }    
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > p->val) {
                successor = cur;
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        return successor;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n1\n
// @lcpr case=end

// @lcpr case=start
// [5,3,6,2,4,null,null,1]\n6\n
// @lcpr case=end

 */

