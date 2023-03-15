#include <iostream>
#include <iterator>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    bool isSymmetricHeler(TreeNode *left, TreeNode *right) {
        if (nullptr == left && nullptr == right) {
            return true;
        }
        if (nullptr == left || nullptr == right || left->val != right->val) {
            return false;
        }
        return isSymmetricHeler(left->left, right->right) && isSymmetricHeler(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        // 这是一种很直白的前序
        return isSymmetricHeler(root, root);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        stack<pair<TreeNode *, TreeNode *>> st;
        st.push(make_pair(root, root));
        while (!st.empty()) {
            auto[lhs, rhs] = st.top();
            st.pop();
            if (nullptr == lhs && nullptr == rhs) {
                continue;
            }
            if (nullptr == lhs || nullptr == rhs || lhs->val != rhs->val) {
                return false;
            }
            st.push(make_pair(lhs->right, rhs->left));
            st.push(make_pair(lhs->left, rhs->right));
        }
        return true;
    }
};

void postTraversal1(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    // 存储待访问节点
    // 约定1、不能有空节点
    stack<TreeNode *> st;

    TreeNode *cur = root;
    // 上一个访问的节点
    TreeNode *pre = nullptr;

    while (cur || !st.empty()) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();
        if (nullptr == cur->right || cur->right == pre) {
            cout << cur->val << "\t" << endl;
            st.pop();
            pre = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
}

void postTraversal3(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    // 存储待访问节点
    // 约定1、不能有空节点
    stack<TreeNode *> st;

    TreeNode* cur = root;
    TreeNode* preHandled = nullptr;
    while (cur || !st.empty()) {
        // cur 是未添加节点
        while (cur) {
            st.push(cur);
            if (cur->left) {
                cur = cur->left;
            } else {
                break;
            }
        }
        if (nullptr == cur) {
            cur = st.top();
        }
        if (!cur->right || cur->right == preHandled) {
            cout << cur->val << "\t";
            preHandled = cur;
            st.pop();
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
}

void postTraversal4(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    // 存储待访问节点
    // 约定1、不能有空节点
    stack<TreeNode *> st;

    TreeNode* cur = root;
    TreeNode* preHandled = nullptr;

    while (cur) {
        st.push(cur);
        cur = cur->left;
    }
    while (!st.empty()) {
        // 至少第二次遇到
        cur = st.top();
        if (nullptr == cur->right || cur->right == preHandled) {
            cout << cur->val << "\t";
            preHandled = cur;
            st.pop();
        } else {
            cur = cur->right;
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
        }
    }
}


void postTraversal2(TreeNode *root) {
    if (nullptr == root) {
        return;
    }
    // 存储待访问节点
    // 约定1、不能有空节点
    stack<TreeNode *> st;

    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (cur) {
        // 所有节点第一次访问
        st.push(cur);
        cur = cur->left;
    }
    while (!st.empty()) {
        // 保证遇到的都是第二次,第三次访问的
        cur = st.top();
        // 第二次 或者第三次
        if (nullptr == cur->right || cur->right == pre) {
            cout << cur->val << "\t";
            pre = cur;
            st.pop();
            continue;
        }
        cur = cur->right;
        while (cur) {
            // 所有节点第一次访问
            st.push(cur);
            cur = cur->left;
        }
    }
}

bool postTraversal(TreeNode *root) {
    if (nullptr == root) {
        return true;
    }
    // 存储待访问节点
    // 约定1、约定可以有空节点
    TreeNode dummy{-1};

    auto gen = [&dummy](TreeNode *node, TreeNode *TreeNode::*lhs, TreeNode *TreeNode::*rhs) {
        stack<TreeNode *> st;
        TreeNode *pre = nullptr;
        TreeNode *cur = node;

        while (cur) {
            st.push(cur);
            cur = cur->*lhs;
        }
        queue<TreeNode *> q;
        return [=, &dummy]() mutable -> TreeNode * {
            while (!st.empty()) {
                if (!q.empty()) {
                    auto res = q.front();
                    q.pop();
                    return res;
                }
                // yield
                if (nullptr == cur) {
                    cur = st.top();
                    q.push(nullptr);
                }
                if (nullptr == cur->*rhs) {
                    q.push(nullptr);
                    pre = cur;
                    st.pop();
                    if (!st.empty()) {
                        cur = st.top();
                    }
                    // push
                    q.push(pre);
                } else if (cur->*rhs && cur->*rhs == pre) {
                    pre = cur;
                    st.pop();
                    if (!st.empty()) {
                        cur = st.top();
                    }
                    // push
                    q.push(pre);
                }
                cur = cur->*rhs;
                while (cur) {
                    st.push(cur);
                    cur = cur->*lhs;
                }
            }
            if (!q.empty()) {
                auto res = q.front();
                q.pop();
                return res;
            }
            return &dummy;
        };
    };

    auto gen1 = gen(root, &TreeNode::left, &TreeNode::right);
    auto gen2 = gen(root, &TreeNode::right, &TreeNode::left);
    for (;;) {
        auto l = gen1();
        auto r = gen2();
        if (nullptr == l && nullptr == r) {
            continue;
        }
        if (nullptr == l || nullptr == r) {
            return false;
        }
        if (&dummy == l && &dummy == r) {
            break;
        }
        if (&dummy == l || &dummy == r) {
            return false;
        }
        if (l->val != r->val) {
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        // 存储待访问节点
        // 约定1、约定可以有空节点
        TreeNode dummy{-1};

        auto gen = [&dummy](TreeNode *node, TreeNode *TreeNode::*lhs, TreeNode *TreeNode::*rhs) {
            stack<TreeNode *> st;
            queue<TreeNode *> q;

            TreeNode *pre = nullptr;
            TreeNode *cur = node;

            return [=, &dummy]() mutable -> TreeNode * {
                while (cur || !st.empty()) {
                    while (cur) {
                        st.push(cur);
                        cur = cur->*lhs;
                        if (nullptr == cur) {
                            q.push(nullptr);
                        }
                    }
                    cur = st.top();
                    if (nullptr == cur->*rhs || (cur->*rhs && cur->*rhs == pre)) {
                        if (nullptr == cur->*rhs) {
                            q.push(nullptr);
                        }
                        q.push(cur);
                        st.pop();
                        pre = cur;

                        cur = nullptr;
                        continue;
                    } else {
                        cur = cur->*rhs;
                    }
                    if (!q.empty()) {
                        auto res = q.front();
                        q.pop();
                        return res;
                    }
                }
                if (!q.empty()) {
                    auto res = q.front();
                    q.pop();
                    return res;
                }
                return &dummy;
            };
        };

        auto gen1 = gen(root->left, &TreeNode::left, &TreeNode::right);
        auto gen2 = gen(root->right, &TreeNode::right, &TreeNode::left);
        for (;;) {
            auto l = gen1();
            auto r = gen2();
            if (nullptr == l && nullptr == r) {
                continue;
            }
            if (nullptr == l || nullptr == r) {
                return false;
            }
            if (&dummy == l && &dummy == r) {
                break;
            }
            if (&dummy == l || &dummy == r) {
                return false;
            }
            if (l->val != r->val) {
                return false;
            }
        }
        return true;
    }
};

// 1,2,2,3,4,4,3
// 关键需要发现边界

void bfs(TreeNode* root) {
    if (nullptr == root) {
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while (q.size() > 1) {
        auto node = q.front();
        q.pop();
        if (node) {
            cout << node->val << "\t";
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        } else {
            cout << endl;
            q.push(nullptr);
        }
    }
}



int main(int argc, char *argv[]) {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);

    root->right->right = new TreeNode(3);
    //cout << Solution{}.isSymmetric(root);
    postTraversal4(root);
}

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct TreeNode {
    struct TreeNode *left, *right;

    int val;

    explicit TreeNode(int val) : val(val), left(left), right(right) {
        auto x = &TreeNode::left;
    }
};

enum Order {
    PRE,
    IN,
    POST,
};

vector<TreeNode *TreeNode::*> children = {&TreeNode::left, &TreeNode::right, nullptr};

void traversal(TreeNode *root, Order order) {
    if (nullptr == root) {
        return;
    }
    for (auto next: children) {
        if (next == children[order]) {
            cout << root->val << "\t";
        }
        if (next == nullptr) {
            return;
        }
        traversal(root->*next, order);
    }
}

bool isNULL(const string &s) {
    return s == "null";
}

TreeNode *makeNode(string value) {
    if (isNULL(value)) {
        return nullptr;
    }
    return new TreeNode(atoi(value.c_str()));
}

TreeNode *makeTree(const vector<std::string> &data) {
    if (data.empty()) {
        return NULL;
    }

    int cur_available_pos = 0;
    TreeNode *root = makeNode(data[cur_available_pos++]);

    assert(root != nullptr);

    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, cur_available_pos));
    cur_available_pos += 2;

    auto addChild = [&](TreeNode *node, int idx, TreeNode *TreeNode::* child) {
        if (idx >= data.size()) {
            return;
        }
        auto newNode = makeNode(data[idx]);
        node->*child = newNode;

        // for child's children
        if (nullptr != newNode) {
            q.push(make_pair(newNode, cur_available_pos));
            cur_available_pos += 2;
        }
    };

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto[node, start] = q.front();
            q.pop();
            // start 必定是合法的
            addChild(node, start, &TreeNode::left);
            addChild(node, start + 1, &TreeNode::right);
        }
    }
    return root;
}


int main(int argc, char *argv[]) {
    auto root = makeTree({"1", "2", "3", "null", "4", "null", "null", "5"});
    traversal(root, PRE);
    cout << endl;
    traversal(root, IN);
    cout << endl;
    traversal(root, POST);
    cout << endl;
}