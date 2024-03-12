/*
 * @lc app=leetcode.cn id=LCR 023 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 023] 相交链表
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
        ListNode* left = headA, *right = headB;
        while (left || right) {
            if (!left) {
                left = headB;
            }
            if (!right) {
                right = headA;
            }
            // 链表拼接
            // A + B
            // B + A
            if (left == right) {
                return left;
            }
            left = left->next;
            right = right->next;
        }
        return NULL;
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

