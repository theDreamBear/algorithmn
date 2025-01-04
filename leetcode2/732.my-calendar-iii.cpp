/*
 * @lc app=leetcode.cn id=732 lang=cpp
 * @lcpr version=30204
 *
 * [732] 我的日程安排表 III
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
// @lcpr-template-end
// @lc code=start
class MyCalendarThree {
public:
    map<int, int> cnt;
    MyCalendarThree() {
    }
    
    int book(int startTime, int endTime) {
        int ans  = 0;
        cnt[startTime]++;
        cnt[endTime]--;
        int ma = 0;
        for (auto& [k, v]: cnt) {
            ans += v;
            ma = max(ma, ans);
        }
        return ma;
    }
};


class MyCalendarThree1 {
public:
    struct Node {
        int l, r, val, add;
        Node* left = nullptr, *right = nullptr;
        Node(int l = 0, int r = 0, int val = 0, int add = 0): l(l), r(r), val(val), add(add){}
    };
    Node* root;

    void set(Node* & node, int l, int r, int add) {
        if (node == nullptr) {
            node = new Node(l, r, add, add);
        } else {
            node->val += add;
            node->add += add;
        }
    }

    void maintain(Node* node) {
        int lv = node->left ? node->left->val : 0;
        int rv = node->right ? node->right->val: 0;
        node->val = max(lv, rv);
    }

    void update(Node* node, int L, int R, int add) {
        if (L <= node->l and node->r <= R) {
            set(node, node->l, node->r, add);
            return;
        }
        int m = (node->l + node->r) / 2;
        if (node->add) {
            set(node->left, node->l, m, node->add);
            set(node->right, m + 1, node->r, node->add);
            node->add = 0;
        }
        if (m >= L) {
            if (!node->left) node->left = new Node(node->l, m);
            update(node->left, L, R, add);
        }
        if (m < R) {
            if (!node->right) node->right = new Node(m + 1, node->r);
            update(node->right, L, R, add);
        }
        maintain(node);
    }

    int query(Node* node, int L, int R) {
        if (!node) {
            return 0;
        }
        if (L <= node->l and node->r <= R) {
            return node->val;
        }
        int m = (node->l + node->r) / 2;
        if (node->add) {
            set(node->left, node->l, m, node->add);
            set(node->right, m + 1, node->r, node->add);
            node->add = 0;
        }
        int ans = 0;
        if (m >= L and node->left) ans = max(ans, query(node->left, L, R));
        if (m < R and node->right) ans = max(ans, query(node->right, L, R));
        return ans;
    }


    MyCalendarThree1() {
        root = new Node(0, 1e9);
    }
    
    int book(int startTime, int endTime) {
        update(root, startTime, endTime - 1, 1);
        return root->val;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendarThree", "book", "book", "book", "book", "book", "book"][[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]\n
// @lcpr case=end

 */

