/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

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
    int len(ListNode* node) {
        int ans = 0;
        while (node) {
            ++ans;
            node = node->next;
        }
        return ans;
    }

    pair<ListNode*, ListNode*> reverseK(ListNode* node, int k) {
        if (!node) {
            return {NULL, NULL};
        }
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* tail = node;
        while (node && k--) {
            next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        tail->next = next;
        return {pre, next};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int sz = len(head);
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* cur = head;
        for (int i = 0; i < sz / k; i++) {
            auto [nh, h] = reverseK(cur, k);
            tail->next = nh;
            tail = cur;
            cur = h;
        }
        if (cur) {
            tail->next = cur;
        }
        return dummy.next;
    }
};
// @lc code=end

