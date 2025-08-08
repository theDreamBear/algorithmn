/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 * @lcpr version=30204
 *
 * [2487] 从链表中移除节点
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
#include <map>
#include <set>
#include <string>
#include <string.h>
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
    ListNode* removeNodes1(ListNode* head) {
        vector<ListNode*> st;
        ListNode* cur = head;
        while (cur) {
            while (!st.empty() and st.back()->val < cur->val) {
                st.pop_back();
            }
            st.push_back(cur);
            cur = cur->next;
        }
        for (int i = 0; i + 1 < st.size(); i++) {
            st[i]->next = st[i + 1];
        }
        st.back()->next = nullptr;
        return st[0];
    }

    // 递归
    ListNode* removeNodes_recursion(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;
        auto node = removeNodes(head->next);
        if (head->val < node->val) {
            return node;
        }
        // 注意此时
        // head 的 next 不一定是node
        head->next = node;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        auto reverse = [](ListNode* node) {
            ListNode* pre = nullptr, *cur = node;
            while (cur) {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            return pre;
        };
        auto h = reverse(head);
        // 删除后面比当前节点小的
        ListNode* cur = h;
        while (cur->next) {
            if (cur->next->val < cur->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        //
        return reverse(h);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,13,3,8]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

