/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (39.46%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 142K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<vector>
using namespace std;

class Solution {
public:
    ListNode* findMid(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return NULL;
        }
        ListNode* slow = node;
        ListNode* fast = node;
        while (fast->next != NULL) {
            if (fast->next->next == NULL) {
                ListNode* tmp = slow;
                slow = slow->next;
                tmp->next = NULL;
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* node) {
        if (node == NULL || node->next == NULL) {
            return node;
        }
        ListNode* tail = node;
        ListNode* cur = node->next;
        tail->next = NULL;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = tail;
            tail = cur;
            cur = next;
        }
        return tail;
    }

    bool isPalindrome(ListNode* head) {
        #ifdef DEBUG  // 存起来再处理  时间复杂度 o(n), 空间复杂度 o(n)
        vector<int> tmp;
        ListNode* cur = head;
        while (cur != NULL) {
            tmp.push_back(cur->val);
            cur = cur->next;
        }
        for (int i = 0, j = tmp.size() - 1; i < tmp.size(); ++i, --j) {
            if (tmp[i] != tmp[j]) {
                return false;
            }
        }
        return true;
         #endif  //  DEBUG

        // 时间复杂度 o(n), 空间复杂度 o(1)
        // 1. 快慢指针找到中间节点
        // 2. 翻转后半截链表
        // 3. 比较左右链表
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* mid = findMid(head);
        ListNode* right = reverseList(mid);
        ListNode* left = head;
        while (left != NULL) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
// @lc code=end

