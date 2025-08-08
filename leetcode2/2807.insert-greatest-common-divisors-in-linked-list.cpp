/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 * @lcpr version=30204
 *
 * [2807] 在链表中插入最大公约数
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
    ListNode* insertGreatestCommonDivisors1(ListNode* head) {
        // 递归, 后序
        if (!head or !head->next) return head;
        auto node = insertGreatestCommonDivisors(head->next);
        auto nd = new ListNode(gcd(head->val, node->val));
        head->next = nd;
        nd->next = node;
        return head;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // 递归, 后序
        if (!head or !head->next) return head;
        ListNode* cur = head;
        while (cur->next) {
            auto nxt = cur->next;
            auto nd = new ListNode(gcd(cur->val, nxt->val));
            cur->next = nd;
            nd->next = nxt;
            cur = nxt;
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [18,6,10,3]\n
// @lcpr case=end

// @lcpr case=start
// [7]\n
// @lcpr case=end

 */

