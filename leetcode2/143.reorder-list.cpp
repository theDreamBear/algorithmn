/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30204
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        if (!head or !head->next) return;
        ListNode* slow = head,  *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* cur = slow->next;
        slow->next = nullptr;

        ListNode* pre = nullptr;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* h1 = head, *h2 = pre;
        while (h1 and h2) {
            ListNode* n1 = h1->next, *n2 = h2->next;
            tail->next = h1;
            tail->next->next = h2;
            h1 = n1, h2 = n2;
            tail = tail->next->next;
        }
        if (h1) tail->next = h1;
        if (h2) tail->next = h2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

