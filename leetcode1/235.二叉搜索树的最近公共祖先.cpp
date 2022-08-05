/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    TreeNode* p{};
    TreeNode* q{};
    TreeNode* ans{};
};

class CommonVisitor : public BinaryTreeVisitor {
private:
    shared_ptr<Frame> p{};
    shared_ptr<Frame> q{};

public:
    CommonVisitor(Order order, void *data) : BinaryTreeVisitor(order, data) {}

protected:
    bool doWhenVisit() override {
        if (currentFrame->node == ((Data*)data)->p) {
            p = currentFrame;
        } else if (currentFrame->node == ((Data*)data)->q) {
            q = currentFrame;
        }
        if (currentFrame->parrent == nullptr) {
            return true;
        }
        return false;
    }

    void afterVisit() override {
        unordered_set<int> hs;
        while (p->parrent) {
            hs.insert(p->node->val);
            p = p->parrent;
        }
        while (q->parrent && hs.count(q->node->val) == 0) {
            q = q->parrent;
        }
        if (nullptr == q) {
            ((Data*)data)->ans = nullptr;
        } else {
            ((Data*)data)->ans = q->node;
        }
    }
};

class Solution {
private:
    Data data;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return nullptr;
        }
        data.p = p;
        data.q = q;
        data.ans = nullptr;
        CommonVisitor visitor(Post_Order, &data);
        visitor.traversal(root);
        return data.ans;
    }
};
// @lc code=end

