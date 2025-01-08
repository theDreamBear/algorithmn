/*
 * @lc app=leetcode.cn id=面试题 02.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.02] 返回倒数第 k 个节点
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
    int kthToLast(ListNode* head, int k) {
        // [end - k, end - 1];
        ListNode* fast = head;
        while (k-- > 0) fast = fast->next;
        ListNode* slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

 */

