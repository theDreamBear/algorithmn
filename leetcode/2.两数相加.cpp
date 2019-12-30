/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.21%)
 * Likes:    3589
 * Dislikes: 0
 * Total Accepted:    282.2K
 * Total Submissions: 779.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbersHelper1(ListNode* source, ListNode* adder) {
        ListNode* head = source;
        ListNode* tail = head;
        ListNode node(0);
        int over = 0;
        while(tail->next != NULL) {
            tail->val += (adder->val + over);
            over = 0;
            if (tail->val >= 10) {
                tail->val -= 10;
                over = 1; 
            }
            tail = tail->next;
            if (adder->next != NULL) {
                adder = adder->next;
            } else {
                adder = &node;
            }
        }
        tail->val += (adder->val + over);
        over = 0;
        if (tail->val >= 10) {
            tail->val -= 10;
            over = 1; 
        }
        if (over == 1) {
            ListNode* nNode = new ListNode(1);
            tail->next = nNode;
        }
        return head;
    }
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        int sz = 0;
        ListNode* cur = l1;
        while(cur) {
            ++ sz;
            cur = cur->next;
        }
        cur = l2;
        while(cur) {
            --sz;
            cur = cur->next;
        }
        if (sz > 0) {
            return addTwoNumbersHelper1(l1, l2);
        } else {
            return addTwoNumbersHelper1(l2, l1);
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* tail = &head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            int sum = 0;
            #ifdef DEBUG
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = 0;
            if (sum >= 10) {
                sum -= 10;
                carry = 1;
            }
            tail->next = new ListNode(sum);
            tail = tail->next;
            #endif // DEBUG

            int x = (l1 == NULL) ? 0 : l1->val;
            int y = (l2 == NULL) ? 0 : l2->val;
            sum = x + y + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        if (carry == 1) {
            tail->next = new ListNode(1);
        }
        return head.next;
    }
};
// @lc code=end

