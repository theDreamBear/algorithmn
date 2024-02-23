/*
 * @lc app=leetcode.cn id=LCR 140 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 140] 训练计划 II
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
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* fast = head;
        int i = 0;
        while (i < cnt) {
            fast = fast->next;
            i++;
        }
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,7,8]\n1\n
// @lcpr case=end

 */

