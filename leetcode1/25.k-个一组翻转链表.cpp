/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    int len(ListNode* node) {
        int ans = 0;
        while (node) {
            ++ans;
            node = node->next;
        }
        return ans;
    }

    pair<ListNode*, ListNode*> reverseK(ListNode* node, int k) {
        ListNode* cur = node;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (cur && k-- > 0) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {pre, next};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. 统计长度
        int sz = len(head);
        if (sz < k || 1 == k) {
            return head;
        }
        // 辅助节点
        ListNode dummuy;
        ListNode* tail = &dummuy;
        // 2. 一组一组的逆序
        ListNode* cur = head;
        int groupLeft = sz / k;
        while (groupLeft-- > 0) {
            auto [pre, next] = reverseK(cur, k);
            tail->next = pre;
            tail = cur;
            cur = next;
        }
        tail->next = cur;
        return dummuy.next;
    }
};
// @lc code=end
