/*
 * @lc app=leetcode.cn id=LCR 155 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 155] 将二叉搜索树转化为排序的双向链表
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList1(Node* root) {
        if (!root) {
            return NULL;
        }
        vector<Node*> data;
        stack<Node*> st;
        Node* cur = root;
        while (cur ||!st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            data.push_back(cur);
            cur = cur->right;
        }
        data[0]->left = data.back();
        data.back()->right = data[0];
        for (int i = 0; i + 1 < data.size(); i++) {
            data[i]->right = data[i + 1];
            data[i + 1]->left = data[i];
        }
        return data[0];
    }

    Node* treeToDoublyList2(Node* root) {
        if (!root) {
            return NULL;
        }
        Node* pre = NULL;
        Node* head = NULL;
        stack<Node*> st;
        Node* cur = root;
        while (cur ||!st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (pre == NULL) {
                head = cur;
            } else {
                pre->right = cur;
                cur->left = pre;
            }
            pre = cur;
            cur = cur->right;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }

    pair<Node*, Node*> treeToDoublyListHelper(Node* root) {
        if (!root->left and !root->right) {
            return {root, root};
        }
        // 后序遍历
        Node* head = root, *tail = root;
        if (root->left) {
            auto left = treeToDoublyListHelper(root->left);
            root->left = left.second;
            left.second->right = root;

             head = left.first;
        }
        if (root->right) {
            auto right = treeToDoublyListHelper(root->right);
            root->right = right.first;
            right.first->left = root;

            tail = right.second;
        }
        return {head, tail};
    }

    Node* treeToDoublyList3(Node* root) {
        if (!root) {
            return NULL;
        }
        auto p = treeToDoublyListHelper(root);
        p.first->left = p.second;
        p.second->right = p.first;
        return p.first;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,5,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

