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

struct Frame {
    constexpr static TreeNode *TreeNode::*next_child[3] = {&TreeNode::left, &TreeNode::right, nullptr};
    TreeNode *node;
    int t;
    shared_ptr<Frame> left{};
    shared_ptr<Frame> right{};

    explicit Frame(TreeNode *node = nullptr, int t = -1, shared_ptr<Frame> left = nullptr,
                   shared_ptr<Frame> right = nullptr,
                   int depth = 0) : node(node), t(t), left(left), right(right){}

    TreeNode *TreeNode::* getNextChild() {
        t++;
        if (t > 2) {
            t = 2;
        }
        return next_child[t];
    }
};

class BinaryTreeVisitor {
private:
    Order order;
    void *data;
    shared_ptr<Frame> currentFrame{};
    stack<shared_ptr<Frame>> st;
    unordered_map<Frame*, void *> priData;

    void setFramePriData(shared_ptr<Frame> frame, void *v) {
        priData[frame.get()] = v;
    }

    void *getFramePriData(shared_ptr<Frame> frame) {
        return priData[frame.get()];
    }

    virtual shared_ptr<Frame> newFrame(TreeNode *node = nullptr) {
        return make_shared<Frame>(node);
    }

    virtual void doWhenVisit() {
        int left = 0, right = 0;
        if (currentFrame->left) {
            left = *(int *) getFramePriData(currentFrame->left);
        }
        if (currentFrame->right) {
            right = *(int *) getFramePriData(currentFrame->right);
        }
        if (!currentFrame->left && !currentFrame->right) {
            setFramePriData(currentFrame, new int(1));
        } else if (!currentFrame->left || !currentFrame->right) {
            if (!currentFrame->left) {
                setFramePriData(currentFrame, new int(right + 1));
            } else {
                setFramePriData(currentFrame, new int(left + 1));
            }
        } else {
            setFramePriData(currentFrame, new int(min(left, right) + 1));
        }
        if (st.empty()) {
            *(int*)data = *(int*)getFramePriData(currentFrame);
        }
    }

public:
    explicit BinaryTreeVisitor(Order order, void *data = nullptr) : order(order), data(data) {}

    void traversal(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        currentFrame = newFrame(root);
        while (currentFrame || !st.empty()) {
            if (!currentFrame) {
                currentFrame = st.top();
                st.pop();
            }
            auto child = currentFrame->getNextChild();
            if (child == Frame::next_child[order]) {
                doWhenVisit();
            }
            if (child) {
                if (currentFrame->node->*child) {
                    auto frame = newFrame(currentFrame->node->*child);
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
    }
};

class Solution {
public:
    int ans{};
    int minDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        BinaryTreeVisitor visitor(Post_Order, &ans);
        visitor.traversal(root);
        return ans;
    }
};
// @lc code=end

