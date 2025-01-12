/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 * @lcpr version=30204
 *
 * [1290] 二进制链表转整数
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = (ans << 1) + head->val;
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,0]\n
// @lcpr case=end

 */

