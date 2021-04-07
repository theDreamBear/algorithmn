/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insert(ListNode* head, ListNode* node) {
        if (!node) {
            return head;
        }
        ListNode* next = node->next;
        node->next = nullptr;
        if (node->val < head->val) {
            node->next = head;
            return insert(node, next);
        }
        ListNode* cur = head;
        while(cur && cur->next && cur->next->val < node->val) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return insert(head, next);
    }

    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* tail = head;
        ListNode* cur = tail->next;
        tail->next = nullptr;
        // 递归
        return insert(tail, cur);
    }
};
// @lc code=end

