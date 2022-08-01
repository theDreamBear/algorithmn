/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    /* 约定
     * 1. 平衡为正数， 且反馈的是该树的高度
     * 2. -1 不平衡
     *
     * */
    int isBalancedHelper(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        int left = isBalancedHelper(root->left);
        int right = isBalancedHelper(root->right);
        if (left < 0 || right < 0 || abs(left - right) > 1) {
            return -1;
        }
        return max(left, right) + 1;
    }

    void isBalancedHelper(TreeNode *root, int &cur) {
        if (nullptr == root) {
            cur = 0;
            return;
        }
        int left = 0;
        isBalancedHelper(root->left, left);

        int right = 0;
        isBalancedHelper(root->right, right);

        if (left < 0 || right < 0 || abs(left - right) > 1) {
            cur = -1;
            return;
        }
        cur = max(left, right) + 1;
    }

    constexpr static TreeNode *TreeNode::*next_child[3] = {&TreeNode::left, &TreeNode::right, nullptr};

    struct Frame {
        TreeNode *node;
        shared_ptr<int> cur;
        shared_ptr<int> leftDepth;
        shared_ptr<int> rightDepth;
        int t;

        explicit Frame(TreeNode *node = nullptr, int cur = 0, shared_ptr<int> leftDepth = nullptr, shared_ptr<int> rightDepth = nullptr,
                       int t = -1) : node(node), cur(new int(0)), leftDepth(leftDepth), rightDepth(rightDepth), t(t) {}

        TreeNode *TreeNode::* getNextChild() {
            t++;
            if (t > 2) {
                t = 2;
            }
            return next_child[t];
        }

        bool update() {
            int l = 0, r = 0;
            if (leftDepth != nullptr) {
                l = *leftDepth;
            }
            if (rightDepth != nullptr) {
                r = *rightDepth;
            }
            if (abs(l - r) > 1) {
                return false;
            }
            *cur = max(l, r) + 1;
            return true;
        }
    };

    bool isBalanced(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        stack<unique_ptr<Frame>> st;
        auto currentFrame = make_unique<Frame>(root);
        while (currentFrame->node || !st.empty()) {
            if (!currentFrame->node) {
                currentFrame = move(st.top());
                st.pop();
            }
            auto child = currentFrame->getNextChild();
            if (child == nullptr) {
                if (!currentFrame->update()) {
                    return false;
                }
                currentFrame->node = nullptr;
                continue;
            }
            if (currentFrame->node->*child) {
                auto frame = make_unique<Frame>(currentFrame->node->*child);
                if (child == &TreeNode::left) {
                    currentFrame->leftDepth = frame->cur;
                } else {
                    currentFrame->rightDepth = frame->cur;
                }
                st.push(std::move(currentFrame));
                currentFrame = std::move(frame);
            }
        }
        return true;
    }
};
// @lc code=end

