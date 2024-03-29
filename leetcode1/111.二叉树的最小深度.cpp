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

#define DefinePrivate(type, name) \
    type name; \
    void set##name(type other) { \
        name = other; \
    } \
    type get##name() {      \
        return name;        \
    }


struct Frame {
    constexpr static TreeNode *TreeNode::*next_child[3] = {&TreeNode::left, &TreeNode::right, nullptr};
    TreeNode *node;
    int t;
    shared_ptr<Frame> left{};
    shared_ptr<Frame> right{};
    shared_ptr<Frame> parrent{};
    DefinePrivate(int ,depth);

    explicit Frame(TreeNode *node = nullptr, int t = -1, shared_ptr<Frame> left = nullptr,
                   shared_ptr<Frame> right = nullptr, shared_ptr<Frame> parrent = nullptr) : node(node), t(t), left(std::move(left)), right(std::move(right)), parrent(std::move(parrent)) {}

    TreeNode *TreeNode::* getNextChild() {
        t++;
        if (t > 2) {
            t = 2;
        }
        return next_child[t];
    }
};


class BinaryTreeVisitor {
protected:
    Order order;
    shared_ptr<Frame> currentFrame{};
    stack<shared_ptr<Frame>> st;
    void* data;
    bool done{};

    virtual shared_ptr<Frame> newFrame(TreeNode *node = nullptr) {
        return make_shared<Frame>(node);
    }

    bool isDone() const {
        return done;
    }

    virtual void afterVisit() {}

    virtual bool doWhenVisit() {
        int left = 0, right = 0;
        if (currentFrame->left) {
            left = currentFrame->left->getdepth();
        }
        if (currentFrame->right) {
            right =currentFrame->right->getdepth();
        }
        if (!currentFrame->left && !currentFrame->right) {
            currentFrame->setdepth(1);
        } else if (!currentFrame->left || !currentFrame->right) {
            if (!currentFrame->left) {
                currentFrame->setdepth(right + 1);
            } else {
                currentFrame->setdepth(left + 1);
            }
        } else {
            currentFrame->setdepth(min(left, right) + 1);
        }
        if (nullptr == currentFrame->parrent) {
            *(int *) data = currentFrame->getdepth();
            return true;
        }
        return false;
    }

public:
    explicit BinaryTreeVisitor(Order order, void *data = nullptr) : order(order), data(data) {}

    void traversal(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        currentFrame = newFrame(root);
        while (!isDone() && (currentFrame || !st.empty())) {
            if (!currentFrame) {
                currentFrame = st.top();
                st.pop();
            }
            auto child = currentFrame->getNextChild();
            if (child == Frame::next_child[order]) {
                if (doWhenVisit()) {
                    done = true;
                }
                if (isDone()) {
                    afterVisit();
                }
            }
            if (!isDone() && child) {
                if (currentFrame->node->*child) {
                    auto frame = newFrame(currentFrame->node->*child);
                    if (child == &TreeNode::left) {
                        currentFrame->left = frame;
                    } else {
                        currentFrame->right = frame;
                    }
                    frame->parrent = currentFrame;
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

