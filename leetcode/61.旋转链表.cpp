/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    int list_size(ListNode* cur) {
        int sz = 0;
        while (cur != nullptr) {
            ++sz;
            cur = cur->next;
        }
        return sz;
    }

    /*
        注三次旋转是左移算法
    */
    void rotate(vector<ListNode*>& vec_nodes, int k) {
        int sz = vec_nodes.size();
        k = sz - k;
        
        auto r = [&vec_nodes](int left, int right) {
            for (int i = left, j = right; i < j; ++i, --j) {
                swap(vec_nodes[i], vec_nodes[j]);
            }
        };
        r(0, k - 1);
        r(k, sz - 1);
        r(0, sz - 1);
    }

    ListNode* reMakeList(vector<ListNode*> vec_nodes) {
        for (int i = 1; i < vec_nodes.size(); ++i) {
            vec_nodes[i - 1]->next = vec_nodes[i];
        }
        // 容易漏掉最后的nextd的重置
        vec_nodes[vec_nodes.size() - 1]->next = nullptr;
        return vec_nodes[0];
    }

    ListNode* violateRotate(ListNode* head, int k) {
        // 存储节点
        vector<ListNode*> vec_nodes;
        ListNode* cur = head;
        while (cur) {
            vec_nodes.push_back(cur);
            cur = cur->next;
        }
        rotate(vec_nodes, k);
        return reMakeList(vec_nodes);
    }

    ListNode* findKth(ListNode* head, int k) {
        ListNode* cur = head;
        while (--k > 0) {
            cur = cur->next;
        }
        return cur;
    }

    ListNode* good(ListNode* head, int sz, int k) {
        ListNode* newTail = findKth(head, sz - k);
        ListNode* newHead = newTail->next;
        ListNode* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }
        newTail->next = nullptr;
        temp->next = head;
        return newHead;
    }

    ListNode* quickAndSmart(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int sz = 1;
        ListNode* cur = head;
        while (cur->next) {
            ++sz;
            cur = cur->next;
        }
        cur->next = head;
        k = k % sz;
        ListNode* newTail = head;
        for (int i = 0; i < sz - k- 1; ++i) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }

    /*
    特殊情况， list为空以及 k == 0
    */
    ListNode* rotateRight1(ListNode* head, int k) {
        // 预处理
        int sz = list_size(head);
        if (sz <= 1) {
            return head;
        }
        k = k % sz;
        if (k == 0) {
            return head;
        }
        // 暴力解法
        // return violateRotate(head, k);

        return good(head, sz, k);
    }

    ListNode* rotateRight(ListNode* head, int k) {
        return quickAndSmart(head, k);
    }
};
// @lc code=end

