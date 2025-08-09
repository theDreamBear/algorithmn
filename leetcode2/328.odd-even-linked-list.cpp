/*
 * @lc app=leetcode.cn id=328 lang=cpp
 * @lcpr version=30204
 *
 * [328] 奇偶链表
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
#include <map>
#include <set>
#include <string>
#include <string.h>
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
    ListNode* oddEvenList1(ListNode* head) {
        ListNode h1, h2;
        ListNode* left = &h1, *right = &h2;
        int id = 1;
        ListNode* cur = head;
        while (cur) {
            ++id;
            ListNode* nxt = cur->next;
            if (id % 2 == 0) {
                left->next = cur;
                left = left->next;
                left->next = nullptr;
            } else {
                right->next = cur;
                right = right->next;
                right->next = nullptr;
            }
            cur = nxt;
        }
        left->next = h2.next;
        return h1.next;
    }

    ListNode* oddEvenList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* eh = head->next;
        ListNode* left = head, *right = eh;
        ListNode* cur = head->next;
        // 循环不变量
        // left->next => right->next
        // right->next = left->next;
        while (right and right->next) {
            left->next = right->next;
            left = left->next;

            right->next = left->next;
            right = right->next;

        }
        left->next = eh;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,3,5,6,4,7]\n
// @lcpr case=end

 */

