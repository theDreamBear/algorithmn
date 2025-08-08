/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 * @lcpr version=30204
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode dummy(0, list1);
        ListNode* cur = &dummy;
        int id = 0;
        // 找前面那一段
        while(cur->next and id < a) {
            cur = cur->next;
            id++;
        }
        ListNode* nxt = cur->next;
        id++;
        cur->next = list2;
        while (cur->next) {
            cur = cur->next;
        }
        while (id <= b) {
            nxt = nxt->next;
            id++;
        }
        cur->next = nxt->next;
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,1,13,6,9,5]\n3\n4\n[1000000,1000001,1000002]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,3,4,5,6]\n2\n5\n[1000000,1000001,1000002,1000003,1000004]\n
// @lcpr case=end

 */

