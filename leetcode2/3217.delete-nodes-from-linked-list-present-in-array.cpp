/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 * @lcpr version=30204
 *
 * [3217] 从链表中移除在数组中存在的节点
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0, head);
        unordered_set<int> hash(nums.begin(), nums.end());
        ListNode* tail = &dummy;
        while (tail->next) {
            if (hash.contains(tail->next->val)) {
                tail->next = tail->next->next;
            } else {
                tail = tail->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n[1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n[1,2,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [5]\n[1,2,3,4]\n
// @lcpr case=end

 */

