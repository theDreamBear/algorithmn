/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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

class EncodeVisitor : public BinaryTreeVisitor {

public:
    EncodeVisitor(Order order, void *data) : BinaryTreeVisitor(order, data) {}

    string toString(int val) {
        auto sVal = to_string(val);
        string ans = "(";
        for (int i = 0; i < sVal.size() - 1; i++) {
            ans.push_back(sVal[i]);
            ans.push_back('_');
        }
        ans.push_back(sVal.back());
        ans.push_back(')');
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

class Codec {
public:
    string getPath(TreeNode *node) {
        if (nullptr == node) {
            return "";
        }
        Data data;
        EncodeVisitor visitor(Post_Order, &data);
        visitor.traversal(node);
        return data.path;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return getPath(root);
    }

    pair<int, int> findChar(const string& data, int left, int high) {
        int l = 0, r = 0;
        while (left <= high && data[left] != '(') {
            ++left;
        }
        ++left;
        ++l;
        int start = left;
        while (left <= high && r < l) {
            if (data[left] == '(') {
                ++l;
            } else if (data[left] == ')') {
                if (++r == l) {
                    break;
                }
            }
            ++left;
        }
        return {start, left - 1};
    }

    pair<TreeNode*, int> childNode(const string& data, int left, int high) {
        auto p = findChar(data, left, high);
        return {deserializeHelper(data, p.first, p.second), p.second};
    }

    TreeNode* deserializeHelper(const string& data, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        if (data.substr(low, high - low + 1).find('(') == string::npos) {
            if (data[low] == 'x') {
                return nullptr;
            }
            int ans = 0;
            int sign = 1;
            if (data[low] == '-') {
                sign = -1;
                ++low;
            }
            for (int i = low; i <= high; i++) {
                if (!isdigit(data[i])) {
                    continue;
                }
                ans = ans * 10 + (data[i] - '0');
            }
            return new TreeNode(ans * sign);
        }
        auto pRoot = childNode(data, low, high);
        auto pLeft = childNode(data, pRoot.second, high);
        auto pRight = childNode(data, pLeft.second, high);
        pRoot.first->left = pLeft.first;
        pRoot.first->right = pRight.first;
        return pRoot.first;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        return deserializeHelper(data, 0, data.size());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

