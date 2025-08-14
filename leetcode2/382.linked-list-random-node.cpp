/*
 * @lc app=leetcode.cn id=382 lang=cpp
 * @lcpr version=30204
 *
 * [382] 链表随机节点
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

mt19937 mt(random_device{}());
uniform_int_distribution<int> u;

class Solution {
public:
    ListNode* head;


    Solution(ListNode* head):head(head) {}

    int getRandom() {
        int i = 0;
        int val = 0;
        auto node = head;
        while (node) {
            int j = u(mt) % (i + 1);
            if (j == 0) val = node->val;
            node = node->next;
            i++;
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end



