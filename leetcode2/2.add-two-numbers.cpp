/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30113
 *
 * [2] 两数相加
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
    int listLen(ListNode* list) {
        int res = 0;
        while (list) {
            res++;
            list = list->next;
        }
        return res;
    }

    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
        int len1 = listLen(l1);
        int len2 = listLen(l2);

        ListNode* left = l1;
        ListNode* right = l2;
        int* ll = &len1;
        int* lr = &len2;

        ListNode* lhead = left;
        ListNode* lpre = NULL;

        if (len1 < len2) {
            left = l2;
            lhead = left;
            right = l1;
            ll = &len2;
            lr = &len1;
        }
        int carrybit = 0;
        while (*ll > 0 && *lr > 0) {
            (*ll)--;
            (*lr)--;

            left->val += (right->val + carrybit);
            carrybit = left->val / 10;
            left->val %= 10;
            lpre = left;
            left = left->next;
            right = right->next;
        }
        while (left && carrybit) {
            left->val += carrybit;
            carrybit = left->val / 10;
            left->val %= 10;
            lpre = left;
            left = left->next;
        }
        if (left == 0 && carrybit) {
            ListNode* node = new ListNode(carrybit);
            lpre->next = node;
        }
        return lhead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        int carrybit = 0;
        while (l1 || l2) {
            int left = l1 ? l1->val : 0;
            int right = l2 ? l2->val : 0;

            int sum = left + right + carrybit;
            carrybit = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carrybit) {
            tail->next = new ListNode(carrybit);
            tail = tail->next;
        }
        return dummy.next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */
