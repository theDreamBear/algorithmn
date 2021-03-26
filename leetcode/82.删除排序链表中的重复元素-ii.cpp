/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    /*
        先存储再处理,简化逻辑
    */
    ListNode* deleteDuplicates1(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;
        while (cur) {
            vec.push_back(cur);
            cur = cur->next;
        }
        ListNode dummy, *tail = &dummy;
        int pre = 0;
        for (int i = 0; i < vec.size();) {
            pre = vec[i]->val;
            int ct = 0;
            while (i < vec.size() && vec[i]->val == pre) {
                ++i;
                ++ct;
            }
            if (ct == 1) {
                tail->next = vec[i - 1];
                tail = tail->next;
                tail->next = NULL;
            }
        }
        return dummy.next;
    }

    ListNode* deleteDuplicates2(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode dummy, *tail = &dummy;
        ListNode* pre = head;
        while (pre && pre->next) {
            ListNode* cur = pre->next;
            int ct = 1;
            while (cur && cur->val == pre->val) {
                ++ct;
                cur = cur->next;
            }
            if (ct == 1) {
                tail->next = pre;
                tail = tail->next;
                tail->next = NULL;
            }
            pre = cur;
        }
        if (pre) {
            tail->next = pre;
        }
        return dummy.next;
    }

    ListNode* deleteDuplicates(ListNode* head) {
         if (!head) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};
// @lc code=end

ListNode* makeNode(vector<int>& data) {
    ListNode dummy, *tail = &dummy;
    for (auto v : data) {
        ListNode* node = new ListNode(v);
        tail->next = node;
        tail = node;
    }
    return dummy.next;
}

int main() {
    vector<int> data{1, 1};
    Solution{}.deleteDuplicates(makeNode(data));
}
