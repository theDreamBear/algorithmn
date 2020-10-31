/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
   struct ListNodeComparator {
       bool operator()(ListNode* left, ListNode* right) {
           return left->val > right->val;
       }
   };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> q;
        for (auto& head : lists) {
            ListNode* cur = head;
            while (cur) {
                q.push(cur);
                cur = cur->next;
            }
        }
        ListNode dummy;
        ListNode* tail = &dummy;
        while (!q.empty()) {
            ListNode* cur = q.top();
            q.pop();
            tail->next = cur;
            tail = tail->next;
        }
        tail->next = NULL;
        return dummy.next;
    }
};
// @lc code=end

