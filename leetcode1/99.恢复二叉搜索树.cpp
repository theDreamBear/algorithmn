/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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

vector<TreeNodeAdapter*> getSeqTreeNode(TreeNodeAdapter* root) {
    vector<TreeNodeAdapter*> data;
    auto beg = ((TreeNodeAdapter*)root)->begin();
    auto end = ((TreeNodeAdapter*)root)->end();
    for (; beg != end; ++beg) {
        data.push_back(beg.node->now);
    }
    return data;
}

class Solution {
public:

    void recoverTree(TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        setTraversal(IN);
        vector<TreeNodeAdapter*> data = getSeqTreeNode((TreeNodeAdapter*)root);

        // 找第一个峰顶
        long long pre = INT64_MIN;
        int left = 0;
        int right = 0;
        for (int i = 0; i + 1 < data.size(); i++) {
            if (data[i]->val > pre && data[i]->val > data[i + 1]->val) {
                left = i;
                break;
            } else {
                pre = data[i]->val;
            }
        }

        // 找最后一个峰谷
        pre = INT64_MAX;
        for (int i = data.size() - 1; i > left; i--) {
            if (data[i]->val < pre && data[i]->val < data[i - 1]->val) {
                right = i;
                break;
            } else {
                pre = data[i]->val;
            }
        }
        swap(data[left]->val, data[right]->val);
    }
};
// @lc code=end

