/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 * @lcpr version=30204
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode* removeZeroSumSublists1(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        for (; cur != nullptr; cur = cur->next) {
            int sum = cur->val;
            if (sum == 0) {
                continue;
            }
            for (int j = nodes.size() - 1; j >= 0; j--) {
                sum += nodes[j]->val;
                if (sum == 0) {
                    while (nodes.size() > j) {
                        nodes.pop_back();
                    }
                    break;
                }
            }
            if (sum != 0) nodes.push_back(cur);
        }
        ListNode dummy;
        ListNode* tail = &dummy;
        for (auto node: nodes) {
            tail->next = node;
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> seen;
        ListNode dummy(0, head);
        int prefix = 0;
        for (ListNode* node = &dummy; node; node = node->next) {
            prefix += node->val;
            seen[prefix] = node;
        }
        prefix = 0;
        for (ListNode* node = &dummy; node; node = node->next) {
            prefix += node->val;
            node->next = seen[prefix]->next;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,-3,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-3,-2]\n
// @lcpr case=end

 */

