/*
 * @lc app=leetcode.cn id=LCR 027 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 027] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
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

        ListNode* oh = head;
        while (oh and pre) {
            if (oh->val != pre->val) {
                return false;
            }
            oh = oh->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

