/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */

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
    TreeNode* buildTreeHelper(vector<int>& inorder, int l1, int h1, vector<int>& postorder, int l2, int h2) {
        if (l1 > h1) {
            return nullptr;
        }
        int val = postorder[h2];
        TreeNode* root = new TreeNode(val);
        int i = l1;
        for (; i <= h1; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        int lsz = i - l1;
        root->left = buildTreeHelper(inorder, l1, i - 1, postorder, l2, l2 + lsz - 1);
        root->right = buildTreeHelper(inorder, i + 1, h1, postorder, l2 + lsz, h2 - 1);
        return root;
    }

    void buildTreeHelper2(vector<int>& inorder, int l1, int h1, vector<int>& postorder, int l2, int h2, TreeNode* &father, TreeNode* TreeNode::*child) {
        if (l1 > h1) {
            return;
        }
        int val = postorder[h2];
        auto node = new TreeNode(val);
        if (nullptr == father) {
            father = node;
        } else {
            father->*child = node;
        }
        int i = l1;
        for (; i <= h1; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        int lsz = i - l1;
        buildTreeHelper2(inorder, l1, i - 1, postorder, l2, l2 + lsz - 1, node, &TreeNode::left);
        buildTreeHelper2(inorder, i + 1, h1, postorder, l2 + lsz, h2 - 1, node, &TreeNode::right);
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //return buildTreeHelper(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
        TreeNode* root = nullptr;
        buildTreeHelper2(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1, root, nullptr);
        return root;
    }

    TreeNode* buildTree_stack(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        struct Item {
            int l1, h1, l2, h2;
            TreeNode* TreeNode::* child;
            TreeNode* father;
            Item() = default;
            Item(int l1, int h1, int l2, int h2, TreeNode* TreeNode::* child, TreeNode* fa) : l1(l1), h1(h1), l2(l2), h2(h2), child(child), father(fa){}
        };
        TreeNode* root = nullptr;
        stack<Item> st;
        st.push(Item(0, (int)inorder.size() - 1, 0, (int)inorder.size() - 1, nullptr, nullptr));
        while (!st.empty()) {
            auto item = st.top(); st.pop();
            int l1 = item.l1;
            int h1 = item.h1;
            int l2 = item.l2;
            int h2 = item.h2;
            auto child = item.child;
            auto father = item.father;
            if (l1 > h1) {
                continue;
            }
            int val = postorder[h2];
            TreeNode* node = new TreeNode(val);
            if (l1 == h1) {
                if (nullptr == root) {
                    root = node;
                } else {
                    node->*child = node;
                }
                continue;
            }
            int i = l1;
            for (; i <= h1; i++) {
                if (inorder[i] == val) {
                    break;
                }
            }
            int lsz = i - l1;
            st.push(Item(l1, i - 1, l2, l2 + lsz - 1, &TreeNode::left, node));
            st.push(Item{0, (int)inorder.size() - 1, 0, (int)postorder.size() - 1, &TreeNode::right, node});
        }
        return root;
    }
};
// @lc code=end

