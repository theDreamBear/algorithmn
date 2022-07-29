/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTreeHelper(vector<int>& preorder, int l1, int h1, vector<int>& inorder, int l2, int h2) {
        if (l1 > h1) {
            return nullptr;
        }
        int val = preorder[l1];
        int i = l2;
        for (; i <= h2; i++) {
            if (inorder[i] == val) {
                break;
            }
        }
        int lsz = i - l2;
        auto root = new TreeNode(val);
        root->left = buildTreeHelper(preorder, l1 + 1, l1 + lsz, inorder, l2, i - 1);
        root->right= buildTreeHelper(preorder, l1 + lsz + 1, h1, inorder, i + 1, h2);
        return root;
    }

    // 最一般的递归构造
    TreeNode* buildTree_recursion(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    struct OneItemTag {
        int l1, h1, l2, h2;
        int tag;
        TreeNode* father;
        OneItemTag(int l1, int h1, int l2, int h2, int tag, TreeNode* fa = nullptr):l1(l1), h1(h1), l2(l2), h2(h2), tag(tag), father(fa){}
    };

    TreeNode* buildTreeTag(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        stack<OneItemTag> st;
        TreeNode* root = nullptr;
        st.push(OneItemTag(0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1, 0, nullptr));

        while (!st.empty()) {
            auto one = st.top();
            st.pop();
            int l1 = one.l1;
            int h1 = one.h1;
            int l2 = one.l2;
            int h2 = one.h2;

            int tag = one.tag;
            TreeNode* father = one.father;
            if (l1 > h1) {
                continue;
            }
            if (l1 == h1) {
                auto node = new TreeNode(preorder[l1]);
                if (father == nullptr) {
                    root = node;
                } else {
                    if (-1 == tag) {
                        father->left = node;
                    } else if (1 == tag) {
                        father->right = node;
                    }
                }
                continue;
            }
            int val = preorder[l1];
            int i = l2;
            for (; i <= h2; i++) {
                if (inorder[i] == val) {
                    break;
                }
            }
            int lsz = i - l2;
            auto node = new TreeNode(val);
            if (father == nullptr) {
                root = node;
            } else {
                if (-1 == tag) {
                    father->left = node;
                } else if (1 == tag) {
                    father->right = node;
                }
            }
            st.push(OneItemTag(l1 + 1, l1 + lsz, l2, i - 1, -1, node));
            st.push(OneItemTag(l1 + lsz + 1, h1, i + 1, h2, 1, node));
        }
        return root;
    }

    struct OneItem {
        int l1, h1, l2, h2;
        TreeNode* TreeNode::*child;
        TreeNode* father;
        OneItem(int l1, int h1, int l2, int h2, TreeNode* TreeNode:: *child, TreeNode* fa = nullptr):l1(l1), h1(h1), l2(l2), h2(h2), child(child), father(fa){}
    };
    // 递归的都能用栈， 用栈场所
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        stack<OneItem> st;
        TreeNode* root = nullptr;
        st.push(OneItem(0, (int)preorder.size() - 1, 0, (int)inorder.size() - 1, nullptr, nullptr));
        while (!st.empty()) {
            auto one = st.top();
            st.pop();
            int l1 = one.l1;
            int h1 = one.h1;
            int l2 = one.l2;
            int h2 = one.h2;
            auto child = one.child;
            TreeNode* father = one.father;
            if (l1 > h1) {
                continue;
            }
            if (l1 == h1) {
                auto node = new TreeNode(preorder[l1]);
                if (father == nullptr) {
                    root = node;
                } else {
                    father->*child = node;
                }
                continue;
            }
            int val = preorder[l1];
            int i = l2;
            for (; i <= h2; i++) {
                if (inorder[i] == val) {
                    break;
                }
            }
            int lsz = i - l2;
            auto node = new TreeNode(val);
            if (father == nullptr) {
                root = node;
            } else {
                father->*child = node;
            }
            st.push(OneItem(l1 + 1, l1 + lsz, l2, i - 1, &TreeNode::left, node));
            st.push(OneItem(l1 + lsz + 1, h1, i + 1, h2, &TreeNode::right, node));
        }
        return root;
    }
};
// @lc code=end

