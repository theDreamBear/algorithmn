/*
 * @lc app=leetcode.cn id=LCR 077 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 077] 排序链表
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
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* mid(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* slow = head, *fast = head->next;
        while (slow and fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 快排
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        // 两个或两个以上节点
        ListNode* tail = mid(head);
        ListNode* right = tail->next;
        // 断开
        tail->next = nullptr;

        //
        ListNode* left = sortList(head);
        right = sortList(right);
        // merge
        ListNode dummy;
        tail = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                tail->next = left;
                tail = tail->next;

                left = left->next;
                tail->next = nullptr;
            } else {
                tail->next = right;
                tail = tail->next;

                right = right->next;
                tail->next = nullptr;
            }
        }
        if (left) {
            tail->next = left;
        }
        if (right) {
            tail->next = right;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [-1,5,3,4,0]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

