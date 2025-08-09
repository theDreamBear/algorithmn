/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 * @lcpr version=30204
 *
 * [2095] 删除链表的中间节点
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
    ListNode* deleteMiddle(ListNode* head) {
        auto findMidPre = [](ListNode* node)->ListNode* {
            if (!node or !node->next) {
                return nullptr;
            }
            ListNode* pre = nullptr;
            ListNode* slow = node, *fast = node;
            do {
                pre = slow;
                slow = slow->next;
                fast = fast->next->next;
            } while (fast and fast->next);
            return pre;
        };
        auto x  = findMidPre(head);
        if (!x) return nullptr;
        x->next = x->next->next;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,4,7,1,2,6]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end

 */

