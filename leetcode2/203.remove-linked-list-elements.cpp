/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
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
    ListNode* removeElements1(ListNode* head, int val) {
        // 空
        if (!head) return nullptr;
        // 头部位置
        if (head->val == val) {
            return removeElements(head->next, val);
        }
        // 非头部
        head->next = removeElements(head->next, val);
        return head;
    }

    ListNode* removeElements2(ListNode* head, int val) {
        ListNode dummy;
        ListNode *tail = &dummy, *node = head;
        while (node) {
            if (node->val != val) {
                tail->next = node;
                tail = tail->next;
                node = node->next;
            } else {
                // 遇到一个删除节点, 需要断开
                tail->next = nullptr;
                node = node->next;
            }
        }
        return dummy.next;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        auto cur = &dummy;
        while (cur->next) {
            auto nxt = cur->next;
            if (nxt->val == val) {
                cur->next = nxt->next;
            } else {
                cur = nxt;
            }
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */

