/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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

struct Data {
    int ans;
};

class DiameterVisitor : public BinaryTreeVisitor {

public:
    DiameterVisitor(Order order, void *data) : BinaryTreeVisitor(order, data) {}

protected:
    bool doWhenVisit() override {
        int left = 0;
        int right = 0;
        if (nullptr != currentFrame->node->left) {
            left = currentFrame->left->extra;
        }
        if (nullptr != currentFrame->node->right) {
            right = currentFrame->right->extra;
        }
        currentFrame->extra = max(left, right) + 1;
        ((Data*)data)->ans = max( ((Data*)data)->ans, left + right + 1);
        return false;
    }
};

class Solution {
public:
    // 返回经过自己的最大值
    int diameterOfBinaryTreeHelper(TreeNode *node, int &max_val) {
        if (nullptr == node) {
            return 0;
        }
        if (nullptr == node->left && nullptr == node->right) {
            max_val = max(1, max_val);
            return 1;
        }
        int left = diameterOfBinaryTreeHelper(node->left, max_val);
        int right = diameterOfBinaryTreeHelper(node->right, max_val);
        max_val = max(left + right + 1, max_val);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree_recursion(TreeNode *root) {
        int max_val{};
        diameterOfBinaryTreeHelper(root, max_val);
        return max_val - 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        Data data;
        data.ans = 0;
        DiameterVisitor visitor(Post_Order, &data);
        visitor.traversal(root);
        return data.ans - 1;
    }
};
// @lc code=end

