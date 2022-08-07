/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    DefinePrivate(string, path);

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
    string path;
};

class SubVisitor : public BinaryTreeVisitor {

public:
    SubVisitor(Order order, void *data) : BinaryTreeVisitor(order, data) {}

    string toString(int val) {
        auto sVal = to_string(val);
        string ans = "[";
        for (int i = 0; i < sVal.size() - 1; i++) {
            ans.push_back(sVal[i]);
            ans.push_back('_');
        }
        ans.push_back(sVal.back());
        ans.push_back(']');
        return ans;
    }
protected:
    bool doWhenVisit() override {
        string left = "(x)";
        string right = "(x)";
        if (currentFrame->left) {
            left = "(" + currentFrame->left->path + ")";
        }
        if (currentFrame->right) {
            right = "(" + currentFrame->right->path + ")";
        }
        currentFrame->path = toString(currentFrame->node->val) + left + right;
        if (nullptr == currentFrame->parrent) {
            ((Data *) data)->path = currentFrame->path;
        }
        return false;
    }
};

class Solution {
public:
    bool isSubtreeHelper(TreeNode *left, TreeNode *right) {
        if (nullptr == left && nullptr == right) {
            return true;
        }
        if (nullptr == left || nullptr == right || left->val != right->val) {
            return false;
        }
        return isSubtreeHelper(left->left, right->left) && isSubtreeHelper(left->right, right->right);
    }

    bool isSubtree_recursion(TreeNode *root, TreeNode *subRoot) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == subRoot->val && isSubtreeHelper(root, subRoot)) {
            return true;
        }
        if (isSubtree(root->left, subRoot)) {
            return true;
        }
        if (isSubtree(root->right, subRoot)) {
            return true;
        }
        return false;
    }

    string getPath(TreeNode *node) {
        if (nullptr == node) {
            return "";
        }
        Data data;
        SubVisitor visitor(Post_Order, &data);
        visitor.traversal(node);
        return data.path;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        auto rp = getPath(root);
        auto sp = getPath(subRoot);
        return rp.find(sp) != string::npos;
    }
};

// @lc code=end

