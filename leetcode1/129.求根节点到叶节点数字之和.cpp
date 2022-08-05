/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
enum Order {
    Pre_Order = 0,
    In_Order = 1,
    Post_Order = 2
};

#define DefinePrivate(type, name) \
    type name{}; \
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
    DefinePrivate(int, extra);

    explicit Frame(TreeNode *node = nullptr, int t = -1, shared_ptr<Frame> left = nullptr,
                   shared_ptr<Frame> right = nullptr, shared_ptr<Frame> parrent = nullptr) : node(node), t(t),
                                                                                             left(std::move(left)),
                                                                                             right(std::move(right)),
                                                                                             parrent(std::move(
                                                                                                     parrent)) {}

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
    void *data;
    bool done{};

    virtual shared_ptr<Frame> newFrame(TreeNode *node = nullptr) {
        return make_shared<Frame>(node);
    }

    bool isDone() const {
        return done;
    }

    virtual void afterVisit() {}

    virtual bool doWhenVisit() {
        return false;
    }

public:
    explicit BinaryTreeVisitor(Order
                               order,
                               void *data = nullptr
    ) :

            order(order), data(data) {}

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

class sumVisitor : public BinaryTreeVisitor {
protected:
    bool doWhenVisit() override {
        if (currentFrame->parrent == nullptr) {
            currentFrame->extra = currentFrame->node->val;
        } else {
            currentFrame->extra = currentFrame->parrent->extra * 10 + currentFrame->node->val;
        }
        if (!currentFrame->node->left && !currentFrame->node->right) {
            *(int*)data += currentFrame->extra;
        }
        return false;
    }

public:
    sumVisitor(Order order, void *data = nullptr) : BinaryTreeVisitor(order, data) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (!root) {
            return ans;
        }
        sumVisitor visitor(Pre_Order, &ans);
        visitor.traversal(root);
        return ans;
    }
};
// @lc code=end

