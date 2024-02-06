/*
 * @lc app=leetcode.cn id=LCR 123 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 123] 图书整理 I
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
    vector<int> reverseBookList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head = pre;
        vector<int> ans;
        cur = pre;
        while (cur) {
            ans.push_back(cur->val);
            cur = cur->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,4,1]\n
// @lcpr case=end

 */

