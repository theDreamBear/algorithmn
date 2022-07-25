/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using VALUE_TYPE  = int;

struct TreeNodeIterator;
enum SEQ{
    PRE = 0,
    IN = 1,
    POST = 2,
};

static SEQ seq = POST;

void setTraversal(int v) {
    if (v == 0) {
        seq = PRE;
    } else if (v == 1) {
        seq = IN;
    } else if (v == 2){
        seq = POST;
    } else {
        seq = PRE;
    }
}


struct TreeNodeAdapter {
    explicit TreeNodeAdapter(const VALUE_TYPE &val, TreeNodeAdapter *left = nullptr, TreeNodeAdapter *right = nullptr) : val(val), left(left), right(right) {}

    TreeNodeIterator begin();

    static TreeNodeIterator end();

    VALUE_TYPE val{};
    struct TreeNodeAdapter *left{}, *right{};

};

struct TreeNodeIteratorImpAbs {
    stack<TreeNodeAdapter *> st;
    TreeNodeAdapter* now{};

    virtual void next(TreeNodeAdapter *node) = 0;

    explicit TreeNodeIteratorImpAbs(TreeNodeAdapter *root) {
        if (root) {
            st.push(root);
        }
    }

    bool getNext() {
        while (!st.empty()) {
            // 当前指针指向栈顶节点
            TreeNodeAdapter *cur = st.top();
            if (cur) {    // 当前节点不为空
                st.pop();
                // TODO:按照各自遍历顺序将节点入栈，入栈中间节点后要入栈一个空节点
                next(cur);
            } else {  //当前节点为空
                // 弹出空节点
                st.pop();
                // 弹出中间节点并将它的值加入结果数组
                now = st.top();
                st.pop();
                return true;
            }
        }
        now = nullptr;
        return false;
    }
};

struct preOrderTreeNodeIteratorImp : public TreeNodeIteratorImpAbs {
    explicit preOrderTreeNodeIteratorImp(TreeNodeAdapter *root) : TreeNodeIteratorImpAbs(root) {}

    void next(TreeNodeAdapter *node) override {
        if (node->right) {
            st.push(node->right);
        }
        if (node->left) {
            st.push(node->left);
        }
        st.push(node);
        st.push(nullptr);
    }
};

struct inOrderTreeNodeIteratorImp : public TreeNodeIteratorImpAbs {
    explicit inOrderTreeNodeIteratorImp(TreeNodeAdapter *root) : TreeNodeIteratorImpAbs(root) {}

    void next(TreeNodeAdapter *node) override {
        if (node->right) {
            st.push(node->right);
        }
        st.push(node);
        st.push(nullptr);
        if (node->left) {
            st.push(node->left);
        }
    }
};

struct postOrderTreeNodeIteratorImp : public TreeNodeIteratorImpAbs {
    explicit postOrderTreeNodeIteratorImp(TreeNodeAdapter *root) : TreeNodeIteratorImpAbs(root) {}

    void next(TreeNodeAdapter *node) override {
        st.push(node);
        st.push(nullptr);
        if (node->right) {
            st.push(node->right);
        }
        if (node->left) {
            st.push(node->left);
        }
    }
};

struct TreeNodeIterator {
    TreeNodeIteratorImpAbs *node;

    explicit TreeNodeIterator(TreeNodeIteratorImpAbs *node) : node(node) {
        node->getNext();
    }

    int &operator*() {
        return node->now->val;
    }

    TreeNodeIterator operator++() {
        node->getNext();
        return *this;
    }

    bool operator!=(TreeNodeIterator other) const {
        return node->now != other.node->now;
    }
};

TreeNodeIterator TreeNodeAdapter::begin() {
    if (seq == PRE) {
        return TreeNodeIterator(new preOrderTreeNodeIteratorImp(this));
    }
    if (seq == IN) {
        return TreeNodeIterator(new inOrderTreeNodeIteratorImp(this));
    }
    return TreeNodeIterator(new postOrderTreeNodeIteratorImp(this));
}

TreeNodeIterator TreeNodeAdapter::end() {
    return TreeNodeIterator(new preOrderTreeNodeIteratorImp(nullptr));
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> data;
        if (!root) {
            return data;
        }
        setTraversal(POST);
        for (auto v : *(TreeNodeAdapter*)(root)) {
            data.push_back(v);
        }
        return data;
    }
};
// @lc code=end

