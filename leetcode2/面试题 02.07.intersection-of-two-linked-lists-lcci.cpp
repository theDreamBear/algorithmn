/*
 * @lc app=leetcode.cn id=面试题 02.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.07] 链表相交
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto getlen = [](ListNode* node) {
            int sz = 0;
            while (node) {
                sz++;
                node = node->next;
            }
            return sz;
        };
        auto l1 = getlen(headA), l2 = getlen(headB);
        while (l1 > l2) {
            headA = headA->next;
            l1--;
        }
        while (l1 < l2) {
            headB = headB->next;
            l2--;
        }
        while (headA and headB) {
            if (headA== headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[0,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */

