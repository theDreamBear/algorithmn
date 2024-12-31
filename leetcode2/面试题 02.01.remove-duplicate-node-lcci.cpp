/*
 * @lc app=leetcode.cn id=面试题 02.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.01] 移除重复节点
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
    ListNode* removeDuplicateNodes1(ListNode* head) {
        map<int, int> hash;
        ListNode dummy;
        ListNode* tail = &dummy;
        while (head) 
        {
            if (hash.count(head->val)) {
                head = head->next;
            } else {
                tail->next = head;
                tail = head;
                head = head->next;
                hash[tail->val] = 1;
                tail->next = nullptr;
            }
        }
        return dummy.next;
    }

    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (head) {
            ListNode* node = dummy.next;
            while (node) {
                if (node->val == head->val) {
                    break;
                }
                node = node->next;
            }
            auto next = head->next;
            if (!node) {
                tail->next= head;
                tail = tail->next;
                tail->next = nullptr;
            }
            head = next;
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 3, 3, 2, 1]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1, 1, 2]\n
// @lcpr case=end

 */

