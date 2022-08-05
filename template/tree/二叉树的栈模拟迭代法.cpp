#include<vector>
#include<stack>
#include<unordered_map>
using namespace std

using VALUE_TYPE  = int;
struct TreeNode {
    explicit TreeNode(const VALUE_TYPE &val, TreeNode *left = nullptr, TreeNode *right = nullptr) : val(val),
                                                                                                    left(left),
                                                                                                    right(right) {}
    VALUE_TYPE val{};
    struct TreeNode *left{}, *right{};

};

TreeNode *makeTree() {
    auto *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    return root;
}

enum Order{
    Pre_Order = 0,
    In_Order = 1,
    Post_Order = 2
};

class Solution {
public:
    constexpr static TreeNode* TreeNode::*next_child[3] = {&TreeNode::left, &TreeNode::right, nullptr};
    struct Frame {
        TreeNode *node;
        int t;

        explicit Frame(TreeNode* node = nullptr, int t = -1) :node(node), t(t){}

        TreeNode* TreeNode::* getNextChild() {
            t++;
            if (t > 2) {
                t = 2;
            }
            return next_child[t];
        }
    };

    vector<int> traversal_simulate_stack(TreeNode *root, Order order = Pre_Order) {
        vector<int> ans;
        if (nullptr == root) {
            return ans;
        }
        stack<Frame> st;
        Frame currentFrame{root};
        while (currentFrame.node || !st.empty()) {
            if (!currentFrame.node) {
                currentFrame = st.top();
                st.pop();
            }
            auto child = currentFrame.getNextChild();
            // order == Pre_Order 先序遍历
            // order == In_Order 中序遍历
            // order == Post_Order 后序遍历
            if (child == next_child[order]) {
                ans.push_back(currentFrame.node->val);
            }
            if (child) {
                if (currentFrame.node->*child) {
                    Frame frame{currentFrame.node->*child};
                    st.push(currentFrame);
                    currentFrame = frame;
                }
                continue;
            }
            currentFrame.node = nullptr;
        }
        return ans;
    }
};

int main() {
    auto pre = Solution{}.traversal_simulate_stack(makeTree(), Pre_Order);
    cout << "Pre_Order:\t";
    for (auto v : pre) {
        cout << v << "\t";
    }
    cout << endl;

    cout << "In_Order:\t";
    auto in = Solution{}.traversal_simulate_stack(makeTree(), In_Order);
    for (auto v : in) {
        cout << v << "\t";
    }
    cout << endl;

    cout << "Post_Order:\t";
    auto post = Solution{}.traversal_simulate_stack(makeTree(), Post_Order);
    for (auto v : post) {
        cout << v << "\t";
    }
}


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