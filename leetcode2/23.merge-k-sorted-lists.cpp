/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30204
 *
 * [23] 合并 K 个升序链表
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
 struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
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
    // 小堆
    ListNode* mergeKLists_pq(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* lhs, ListNode* rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        ListNode dummy;
        ListNode* tail = &dummy;
        for (auto node: lists) {
            if (node) {
                pq.emplace(node);
            }
        }
        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            tail->next = node;
            tail = node;
            node = node->next;
            if (node) {
                pq.emplace(node);
            }
        }
        return dummy.next;
    }

    ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;
        while (l1 or l2) {
            if (!l1) {
                tail->next = l2;
                break;
            }
            if (!l2) {
                tail->next = l1;
                break;
            }
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, int l, int r) {
        assert(l >= 0 and r < (int)lists.size());
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }
        int m= l + (r - l) / 2;
        auto left = mergeKLists(lists, l, m);
        auto right = mergeKLists(lists, m + 1, r);
        return mergeTwo(left, right);
    }
    // 分治
    ListNode* mergeKLists_div(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    // 类似希尔排序的归并
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        for (int step = 1; step < n; step *= 2) {
            for (int i = 0; i + step < n; i += step * 2) {
                lists[i] = mergeTwo(lists[i], lists[i + step]);
            }
        }
        return lists[0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

