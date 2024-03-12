/*
 * @lc app=leetcode.cn id=LCR 025 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 025] 两数相加 II
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
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
// @lcpr-template-end
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    tuple<ListNode*, ListNode*, int> reverseList(ListNode* node) {
        if (!node) {
            return {NULL, NULL, 0};
        }
        int len = 0;
        ListNode* pre = NULL, *cur = node;
        while (cur) {
            ++len;
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {pre, node, len + 1};
    }

    // pass
    ListNode* addTwoNumbers_逆序(ListNode* l1, ListNode* l2) {
        // 逆序
        auto [left, lta,len] = reverseList(l1);
        auto [right, rta, ren] = reverseList(l2);
        int carry = 0;
        ListNode* tail = NULL;
        ListNode* other = NULL;
        ListNode* head = NULL;
        if (len >= ren) {
            tail = left;
            other = right;
        } else {
            tail = right;
            other = left;
        }
        head = tail;
        // 多补一个节点用于进位
        lta->next = new ListNode(0);
        rta->next = new ListNode(0);
        while (tail) {
            tail->val += (other ? other->val : 0) + carry;
            carry = tail->val / 10;
            tail->val %= 10;
            tail = tail->next;
            if (other) {
                other = other->next;
            }
        }
        auto [r, ta, l] = reverseList(head);
        while (r and r->val == 0) {
            r = r->next;
        }
        if (!r) {
            return new ListNode(0);
        }
        return r;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> ls, rs;
        ListNode ld, rd;
        ld.next = l1;
        rd.next = l2;
        ListNode* cur = &ld;
        while (cur) {
            ls.push(cur);
            cur = cur->next;
        }
        cur = &rd;
        while (cur) {
            rs.push(cur);
            cur = cur->next;
        }
        int carry = 0;

        ListNode* pre = NULL;
        ListNode* v;
        while (!ls.empty() || !rs.empty()) {
            int lt = ls.empty() ? 0 : (v = ls.top(), ls.pop(), v->val);
            int rt = rs.empty() ? 0 : (v = rs.top(), rs.pop(), v->val);

            auto node = new ListNode(lt + rt + carry);
            carry = node->val / 10;
            node->val %= 10;
            node->next = pre;
            pre = node;
        }
        while (pre and pre->val == 0) {
            pre = pre->next;
        }
        if (!pre) {
            return new ListNode(0);
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

