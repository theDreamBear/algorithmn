/*
 * @lc app=leetcode.cn id=LCR 024 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 024] 反转链表
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
    pair<ListNode*, ListNode*> reverseListHelper(ListNode* head) {
        if (!head || !head->next) {
            return {head, head};
        }
        auto [nh, nt] = reverseListHelper(head->next);
        nt->next = head;
        head->next = NULL;
        return {nh, head};
    }

    ListNode* reverseList1(ListNode* head) {
        // 0个或者1个
        if (!head || !head->next) {
            return head;
        }
        auto [nh, nt] = reverseListHelper(head);
        return nh;
    }

    ListNode* reverseList(ListNode* head) {
        // 0个或者1个
        if (!head) {
            return head;
        }
        ListNode* pre = NULL, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

