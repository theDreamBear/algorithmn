/*
 * @lc app=leetcode.cn id=LCR 171 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 171] 训练计划 V
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
    int len(ListNode *headA) {
        if (!headA) {
            return 0;
        }
        ListNode* cur = headA;
        int ans = 0;
        while (cur) {
            ans++;
            cur = cur->next;
        }
        return ans;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = len(headA);
        int l2 = len(headB);
        if (l1 * l2 == 0) {
            return nullptr;
        }
        ListNode* a = headA, *b = headB;
        while (l1 != l2) {
            if (l1 > l2) {
                 a = a->next;
                 l1--;
            } else  {
                b = b->next;
                l2--;
            }
        }
        while (a and b) {
            if (a->val == b->val) {
                return a;
            } else {
                a = a->next;
                b = b->next;
            }
        }
        return nullptr;
    }

    // 方法二， 遍历A, 存起来， 出现了相同就OK
    // 有没有不用额外遍历一遍的方法吗？
    // 
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

