/*
 * @lc app=leetcode.cn id=LCR 136 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 136] 删除链表的节点
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        if (head->val == val) {
            return head->next;
        }
        ListNode* cur = head;
        while (cur and cur->next and cur->next->val != val) {
            cur = cur->next;
        }
        if (cur and cur->next and cur->next->val == val) {
            cur->next = cur->next->next;
        }
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */

