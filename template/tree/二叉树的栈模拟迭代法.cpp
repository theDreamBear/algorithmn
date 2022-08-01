#include<vector>
#include<stack>
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