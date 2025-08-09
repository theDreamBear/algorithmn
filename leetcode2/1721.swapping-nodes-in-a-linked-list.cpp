/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 * @lcpr version=30204
 *
 * [1721] 交换链表中的节点
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
    ListNode* swapNodes(ListNode* head, int k) {
        auto findRevsrseK = [](ListNode* node, int k) {
            ListNode* slow = node, *fast = node;
            while (k--) {
                fast = fast->next;
            }
            while (fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        };
        auto findK = [](ListNode* node, int k) {
            ListNode* slow = node;
            while (--k) {
                slow = slow->next;
            }
            return slow;
        };

        auto a = findK(head, k), b = findRevsrseK(head, k);
        swap(a->val, b->val);
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [7,9,6,6,7,8,3,0,9,5]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n2\n
// @lcpr case=end

 */

