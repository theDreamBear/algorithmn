/*
 * @lc app=leetcode.cn id=面试题 02.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.06] 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        while (head) {
            ans.push_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = ans.size() - 1; i < j; i++, j--) {
            if (ans[i] != ans[j]) return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1->2\n
// @lcpr case=end

// @lcpr case=start
// 1->2->2->1\n
// @lcpr case=end

 */

