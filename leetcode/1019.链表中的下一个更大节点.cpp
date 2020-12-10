/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        O(n^2)
    */
    vector<int> nextLargerNodes_violate(ListNode* head) {
        vector<int> ans;
        // 0
        if (head == NULL) {
            return ans;
        }
        // 1
        ListNode* cur = head;
        while (cur->next != NULL) {
           ListNode* temp = cur->next;
           while (temp != NULL && temp->val <= cur->val) {
               temp = temp->next;
           }
           if (temp == NULL) {
               ans.push_back(0);
           } else {
               ans.push_back(temp->val);
           }
            cur = cur->next;
        }
        ans.push_back(0);
        return ans;
    }

    /*

    */
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        // 0
        if (head == NULL) {
            return ans;
        }
        // 1
        ListNode* cur = head;
        vector<int> source;
        while (cur != NULL) {
            source.push_back(cur->val);
            cur = cur->next;
        }
        ans = vector<int>(source.size(), 0);
        stack<int> decrease;
        for (int i = 0 ; i < source.size(); ++i) {
            // 注意是不严格递减栈
            if (decrease.empty() || source[decrease.top()] >= source[i]) {
                decrease.push(i);
            } else {
                while (!decrease.empty() && source[decrease.top()] < source[i]) {
                    int pos = decrease.top();
                    decrease.pop();
                    ans[pos] = source[i];
                }
                if (decrease.empty() || source[decrease.top()] >= source[i]) {
                    decrease.push(i);
                }
            }
        }
        while (!decrease.empty()) {
            int pos = decrease.top();
            decrease.pop();
            ans[pos] = 0;
        }
        return ans;
    }
};
// @lc code=end

