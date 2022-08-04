/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
class Solution1 {
public:
    int minDepthHelper(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        if (!root->left) {
            return minDepthHelper(root->right) + 1;
        }
        if (!root->right) {
            return minDepthHelper(root->left) + 1;
        }
        int left = minDepthHelper(root->left);
        int right = minDepthHelper(root->right);
        return min(left, right) + 1;
    }
    int minDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        return minDepthHelper(root);
    }
};

enum Order {
    Pre_Order = 0,
    In_Order = 1,
    Post_Order = 2
};

class Solution {
public:
    constexpr static TreeNode *TreeNode::*next_child[3] = {&TreeNode::left, &TreeNode::right, nullptr};

    struct Frame {
        Frame *left;
        Frame *right;
        int depth;
        TreeNode *node;
        int t;

        explicit Frame(TreeNode *node = nullptr, int t = -1, Frame *left = nullptr, Frame *right = nullptr,
                       int depth = 0) : node(node), t(t), left(left), right(right), depth(0) {}

        TreeNode *TreeNode::* getNextChild() {
            t++;
            if (t > 2) {
                t = 2;
            }
            return next_child[t];
        }
    };

    int traversal_simulate_stack(TreeNode *root, Order order = Pre_Order) {
        if (nullptr == root) {
            return 0;
        }
        int ans = 0;
        stack<Frame *> st;
        Frame *currentFrame = new Frame{root};
        while (currentFrame || !st.empty()) {
            if (!currentFrame) {
                currentFrame = st.top();
                st.pop();
            }
            auto child = currentFrame->getNextChild();
            // order == Pre_Order 先序遍历
            // order == In_Order 中序遍历
            // order == Post_Order 后序遍历
            if (child == next_child[order]) {
                do {
                    if (!currentFrame->left && !currentFrame->right) {
                        currentFrame->depth = 1;
                        continue;
                    }
                    if (!currentFrame->left || !currentFrame->right) {
                        if (!currentFrame->left) {
                            currentFrame->depth = currentFrame->right->depth + 1;
                        } else {
                            currentFrame->depth = currentFrame->left->depth + 1;
                        }
                        continue;
                    }
                    currentFrame->depth = min(currentFrame->left->depth, currentFrame->right->depth) + 1;
                } while (false);
                if (st.empty()) {
                    ans = currentFrame->depth;
                }
            }
            if (child) {
                if (currentFrame->node->*child) {
                    Frame *frame = new Frame{currentFrame->node->*child};
                    if (child == &TreeNode::left) {
                        currentFrame->left = frame;
                    } else {
                        currentFrame->right = frame;
                    }
                    st.push(currentFrame);
                    currentFrame = frame;
                }
                continue;
            }
            currentFrame = nullptr;
        }
        return ans;
    }

    int minDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        return traversal_simulate_stack(root, Post_Order);
    }
};
// @lc code=end

