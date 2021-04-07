/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* findPreMid(ListNode* node) {
        ListNode* slow = node;
        ListNode* fast = node->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* node) {
        if (!node || !node->next) {
            return node;
        }
        ListNode* pre = nullptr;
        ListNode* cur = node;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        ListNode* preMid = findPreMid(head);
        ListNode* mid = preMid->next;
        preMid->next = nullptr;
        ListNode* reverseHead = reverseList(mid);
        ListNode dummy;
        ListNode* newHead = &dummy;
        ListNode* newTail = newHead;
        while(head && reverseHead) {
            newTail->next = head;
            newTail = head;
            head = head->next;
            newTail->next = reverseHead;
            newTail = reverseHead;
            reverseHead = reverseHead->next;
        }
        if (head) {
            newTail->next = head;
            newTail = head;
            newTail->next = nullptr;
        }
        head = dummy.next;
    }
};
// @lc code=end

