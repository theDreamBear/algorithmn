/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
 */
#include <functional>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    TreeNode* getP(TreeNode* root, int x) {
        if (root == NULL) {
            return NULL;
        }
        if ((root->left && root->left->val == x) ||
            (root->right && root->right->val == x)) {
            return root;
        }
        TreeNode* lc = getP(root->left, x);
        if (lc) {
            return lc;
        }
        TreeNode* rc = getP(root->right, x);
        return rc;
    }

    TreeNode* getLeftC(TreeNode* root, int x) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == x) {
            return root->left;
        }
        TreeNode* lc = getLeftC(root->left, x);
        if (lc) {
            return lc;
        }
        TreeNode* rc = getLeftC(root->right, x);
        return rc;
    }

    union U {
        TreeNode* ans;
        long long val;
    };

    struct visitHelper {
        U un;

        function<void(TreeNode*, U*, int x)> fn;

        visitHelper(TreeNode* node = NULL) { un.ans = node; }

        void setFn(const function<void(TreeNode*, U*, int x)>& f) {
            reset();
            fn = f;
        }

        void reset() { un.val = 0; }

        void operator()(TreeNode* root, int x) { fn(root, &un, x); }
    };

    static void valueNode(TreeNode* node, U* u, int x) {
        if (NULL == node) {
            return;
        }
        if (node && node->val == x) {
            u->ans = node;
        }
        return;
    }

    static void childNum(TreeNode* node, U* u, int x) {
        if (NULL == node) {
            return;
        }
        ++u->val;
    }

    void preorderTraversal(TreeNode* root, int x, visitHelper& vh) {
        if (NULL == root) {
            return;
        }
        vh(root, x);
        if (root->left) {
            preorderTraversal(root->left, x, vh);
        }
        if (root->right) {
            preorderTraversal(root->right, x, vh);
        }
    }

    TreeNode* getX(TreeNode* root, int x) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == x) {
            return root;
        }
        TreeNode* lc = getX(root->left, x);
        if (lc) {
            return lc;
        }
        TreeNode* rc = getX(root->right, x);
        return rc;
    }

    int getChildNum(TreeNode* x) {
        if (x == NULL) {
            return 0;
        }
        int cur = 1;
        cur += getChildNum(x->right);
        cur += getChildNum(x->left);
        return cur;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // TreeNode* node = getX(root, x);
        visitHelper vh;

        vh.setFn(valueNode);

        vh.reset();
        preorderTraversal(root, x, vh);
        TreeNode* node = vh.un.ans;

        vh.reset();
        vh.setFn(childNum);
        preorderTraversal(node, x, vh);
        int xn = vh.un.val;

        if (n > 2 * xn) {
            return true;
        }
        if (node) {
            cout << node->val << endl;
        }
        int ln = 0, rn = 0;

        vh.reset();
        preorderTraversal(node->left, x, vh);
        ln = vh.un.val;

        vh.reset();
        preorderTraversal(node->right, x, vh);
        rn = vh.un.val;

        return 2 * max(ln, rn) > n;
    }
};
// @lc code=end
