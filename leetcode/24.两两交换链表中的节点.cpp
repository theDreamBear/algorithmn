/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <stddef.h>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode* cur = head;
        head = cur->next;
        ListNode* pre = NULL;
        while (NULL != cur) {
            ListNode* next = cur->next;
            if (NULL == cur->next) {
                break;
            }
            ListNode* third = next->next;
            cur->next = third;
            next->next = cur;
            if (NULL == pre) {
                pre = cur;
            } else {
                pre->next = next;
                pre = cur;
            }
            cur = third;
        }
        return head;
    }
};
// @lc code=end
