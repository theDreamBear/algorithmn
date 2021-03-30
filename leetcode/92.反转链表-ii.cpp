/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next) {
            return head;
        }
        ListNode* pre = NULL, *next = NULL;
        int index = 1;
        ListNode* cur = head;
        // 找pre
        while (cur && index < left - 1) {
            cur = cur->next;
            ++index;
        } 
        // 存在pre
        if (index == left - 1) {
            pre = cur;
        }
        while (cur && index < right) {
            cur = cur->next;
            ++index;
        }
        // 存在next
        if (cur) {
            next = cur->next;
            cur->next = NULL;
        }
        // 反转链表
        ListNode* p = next;
        ListNode* temp = pre;
        if (pre == NULL) {
            temp = head;
        } else {
            temp = temp->next;
        }
        while (temp) {
            ListNode* n = temp->next;
            temp->next = p;
            p = temp;
            temp = n;
        }
        if (pre) {
            pre->next = p;
            return head;
        }
        return p;  
    }
};
// @lc code=end
