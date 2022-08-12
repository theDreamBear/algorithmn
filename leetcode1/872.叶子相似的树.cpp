/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
struct PreOrderTraversal {
public:
    stack<TreeNode *> st;
    TreeNode *cur{};

    TreeNode *nextLeaf(TreeNode *node = nullptr) {
        if (!st.empty() && nullptr != node) {
            return nullptr;
        }
        if (node) {
            cur = node;
        }
        TreeNode *ans = nullptr;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                if (!cur->left && !cur->right) {
                    ans = cur;
                }
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            cur = cur->right;
            if (nullptr != ans) {
                break;
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        if (nullptr == root1 && nullptr == root2) {
            return true;
        }
        if (nullptr == root1 || nullptr == root2) {
            return false;
        }
        PreOrderTraversal left, right;
        TreeNode *l = left.nextLeaf(root1);
        TreeNode *r = right.nextLeaf(root2);
        while (l && r && l->val == r->val) {
            l = left.nextLeaf();
            r = right.nextLeaf();
        }
        return nullptr == l && nullptr == r;
    }
};
// @lc code=end

