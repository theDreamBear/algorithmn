/*
 * @lc app=leetcode.cn id=面试题 02.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.05] 链表求和
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy, *tail = &dummy;
        int carry = 0;
        while (l1 or l2) {
            int lv = l1 ? l1->val: 0;
            int rv = l2 ? l2->val: 0;
            int sum = (lv + rv + carry);
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = (sum / 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            tail->next = new ListNode(1);
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// (7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295\n
// @lcpr case=end

// @lcpr case=start
// (6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295\n
// @lcpr case=end

 */

