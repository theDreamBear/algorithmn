/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;

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
    ListNode* finPreMid(ListNode* node) {
        if (!node || !node->next) {
            return node;
        }
        ListNode* slow = node;
        ListNode* fast = node->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* divideSort(ListNode* node) {
        if (!node || !node->next) {
            return node;
        }
        ListNode* preMid = finPreMid(node);
        ListNode* mid = preMid->next;
        preMid->next = nullptr;
        ListNode* left = divideSort(node);
        ListNode* right = divideSort(mid);

        ListNode dummy;
        ListNode* tail = &dummy;
        while (left && right) {
            if (left->val < right->val) {
                tail->next = left;
                tail = left;
                left = left->next;
            } else {
                tail->next = right;
                tail = right;
                right = right->next;
            }
        }
        if (left) {
            tail->next = left;
        } else if (right) {
            tail->next = right;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        return divideSort(head);
    }
};
// @lc code=end
