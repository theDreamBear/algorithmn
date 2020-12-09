/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
    /*
     [head, p) 小于 x 节点区间
     [p,cur) 大于等于 x
     注意快排的 partition 会打乱顺序, 这地方使用不太行
    */
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode small(0), big(0);

        ListNode* sTail = &small;
        ListNode* bTail = &big;

        ListNode* cur = head;
        while (NULL != cur) {
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = NULL;
            if (temp->val < x) {
                sTail->next = temp;
                sTail = sTail->next;
            } else {
                bTail->next = temp;
                bTail = bTail->next;
            }
        }
        sTail->next = big.next;
        return small.next;
    }
};
// @lc code=end
