/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 * @lcpr version=30204
 *
 * [2058] 找出临界点之间的最小和最大距离
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head or !head->next) return {-1, -1};
        int first = -1, last = -1;
        int val = -1;
        int mm = INT_MAX, ma = -1;
        ListNode* node = head;
        int id = 0;
        while (node->next) {
            ListNode* next = node->next;
            // pre节点
            if (val != -1) {
                if ((val > node->val and next->val > node->val) or (val < node->val and next->val < node->val)) {
                    if (first == -1) {
                        first = id;
                    } else {
                        ma = id - first;
                    }
                    if (last == -1) {
                        last = id;
                    } else {
                        mm = min(mm, id - last);
                    }
                    last = id;
                }
            }
            val = node->val;
            node = next;
            id++;
        }
        if (mm == INT_MAX) {
            return {-1, -1};
        }
        return {mm, ma};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,3,1,2,5,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,2,3,2,2,2,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3,2]\n
// @lcpr case=end

 */

