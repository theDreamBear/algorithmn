/*
 * @lc app=leetcode.cn id=725 lang=cpp
 * @lcpr version=30204
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto size = [&](ListNode* node) {
            int sz = 0;
            while (node) {
                ++sz;
                node = node->next;
            }
            return sz;
        };
        auto split = [&](ListNode* &node, int step)->ListNode* {
            if (step == 0) {
                return nullptr;
            }
            ListNode* h = node;
            while (step-- > 1) {
                node = node->next;
            }
            ListNode* next = node->next;
            node->next = nullptr;
            node = next;
            return h;
        };
        vector<ListNode*> ans(k, nullptr);

        int len = size(head);
        int d = len / k, a = len % k;
        for (int i = 0; i < k; i++) {
            ans[i] = split(head, i < a ? d + 1 : d);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,6,7,8,9,10]\n3\n
// @lcpr case=end

 */

