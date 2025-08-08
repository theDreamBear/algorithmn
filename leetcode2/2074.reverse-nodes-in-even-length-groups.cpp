/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 * @lcpr version=30204
 *
 * [2074] 反转偶数长度组的节点
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        auto size = [](ListNode* node) {
            int len = 0;
            ListNode* cur = node;
            while (cur) {
                len++;
                cur = cur->next;
            }
            return len;
        };

        auto reverse = [](ListNode* node) {
            ListNode* pre = nullptr;
            while (node) {
                ListNode* nxt = node->next;
                node->next = pre;
                pre = node;
                node = nxt;
            }
            return pre;
        };

        auto remove = [&](auto&& self, ListNode* node, int i, int left)->ListNode* {
            // 边界条件
            if (left <= i) {
                // 最后一个
                if (left % 2 == 0) {
                    return reverse(node);
                }
                return node;
            }
            ListNode* cur = node;
            int t = i;
            while (t-- > 1) {
                cur = cur->next;
            }
            auto nd = self(self, cur->next, i + 1, left - i);
            cur->next = nullptr;
            if (i % 2 == 0) {
                ListNode* oh = node;
                node = reverse(node);
                cur = oh;
            }
            cur->next = nd;
            return node;
        };

        int len = size(head);
        return remove(remove, head, 1, len);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,2,6,3,9,1,7,3,8,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,6]\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n
// @lcpr case=end

 */

