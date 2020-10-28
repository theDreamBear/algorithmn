/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
        if (NULL == root) {
            return;
        }
        nodes.push_back(root);
        preorderTraversal(root->left, nodes);
        preorderTraversal(root->right, nodes);
    }

    void flatten1(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) {
            return;
        }
        vector<TreeNode*> nodes;
        preorderTraversal(root, nodes);
        TreeNode* head = nodes[0];
        TreeNode* tail = head;
        head->left = NULL;
        head->right = NULL;

        for (auto& x : nodes) {
            x->left = NULL;
            x->right = NULL;
            tail->right = x;
            tail = x;
        }
        return;
    }

    void flatten2(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }

    void flatten3(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        flatten3(root->left);
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;
        while (root->right) {
            root = root->right;
        }
        flatten3(right);
        root->right = right;
    }

    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = NULL;
        pre = root;
    }
};
// @lc code=end
