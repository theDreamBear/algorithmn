/*
 * @lc app=leetcode.cn id=817 lang=cpp
 * @lcpr version=30204
 *
 * [817] 链表组件
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
    int numComponents(ListNode* head, vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hash(nums.begin(), nums.end());
        ListNode* node = head;
        while (node) {
            // 找到一个
            if (hash.count(node->val)) {
                ans++;
                while (node->next and hash.count(node->next->val)) {
                    node = node->next;
                }
            }
            node = node->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3]\n[0,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,3,4]\n[0,3,1,4]\n
// @lcpr case=end

 */

