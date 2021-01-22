/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Node {
 public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
    void postTraversal(Node* node, vector<int>& result) {
        if (node == NULL) {
            return;
        }
        for (auto& child : node->children) {
            postTraversal(child, result);
        }
        result.push_back(node->val);
    }

    /*
        中 右 左 访问顺序, 逆序就变成了 后续遍历
    */
    void postTraversal_loop(Node* node, vector<int>& result) {
        if (node == NULL) {
            return;
        }
        stack<Node*> st;
        st.push(node);
        while (!st.empty()) {
            Node* cur = st.top();
            result.push_back(cur->val);
            st.pop();
            for (auto& child : cur->children) {
                st.push(child);
            }
        }
        reverse(result.begin(), result.end());
    }


    struct VisitNode {
        Node* node;
        int visitIndex;

        VisitNode(Node* n) {
            node = n;
            visitIndex = 0;
        }

        VisitNode() { node = NULL; }

        VisitNode nextChild() {
            if (node == NULL) {
                return VisitNode();
            }
            if (visitIndex < node->children.size()) {
                Node* n = node->children[visitIndex];
                ++visitIndex;
                return VisitNode(n);
            }
            return VisitNode();
        }
    };

    void postTraversal_loop2(Node* node, vector<int>& result) {
        if (node == NULL) {
            return;
        }
        stack<VisitNode> st;
        VisitNode cur(node);
        while (cur.node || !st.empty()) {
            while (cur.node) {
                st.push(cur);
                cur = cur.nextChild();
            }
            cur = st.top().nextChild();
            if (cur.node == NULL) {
                result.push_back(st.top().node->val);
                st.pop();
            }
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> result;
        postTraversal_loop(root, result);
        return result;
    }
};
// @lc code=end
