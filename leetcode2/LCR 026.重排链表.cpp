/*
 * @lc app=leetcode.cn id=LCR 026 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 026] 重排链表
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
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
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
    void reorderList1(ListNode* head) {
        vector<ListNode*> data;
        ListNode* cur = head;
        while (cur) {
            data.push_back(cur);
            cur = cur->next;
        }
        ListNode dummy;
        ListNode* tail = &dummy;
        int i = 0, j = data.size() - 1;
        for (; i < j; i++, j--) {
            tail->next = data[i];
            data[i]->next = data[j];
            data[j]->next = nullptr;
            tail = tail->next->next;
        }
        if (i == j) {
            tail->next = data[i];
            data[i]->next = nullptr;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        // 拆链表
        ListNode* slow = head, *fast = head->next;
        while (slow and fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* nh = slow->next;
        slow->next = nullptr;

        // 逆序
        ListNode* pre = NULL;
        ListNode* cur = nh;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* oh = head;
        while (oh || pre) {
            if (oh) {
                tail->next = oh;
                tail = tail->next;
                oh = oh->next;
            }
            if (pre) {
                tail->next = pre;
                tail = tail->next;
                pre = pre->next;
            }
        }
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

