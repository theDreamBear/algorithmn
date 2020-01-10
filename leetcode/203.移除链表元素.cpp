/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (43.17%)
 * Likes:    325
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 122.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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
#include <iostream>
using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return head;
        }
        ListNode dummp(-1);
        dummp.next = head;
        ListNode* cur = head;
        ListNode* tail = &dummp;
        while(cur!= NULL) {
            if (cur->val != val) {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
        }
        tail->next = NULL;
        return dummp.next; 
    }
};
// @lc code=end

