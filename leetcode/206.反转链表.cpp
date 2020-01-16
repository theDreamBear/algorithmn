/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (66.00%)
 * Likes:    732
 * Dislikes: 0
 * Total Accepted:    143.2K
 * Total Submissions: 215.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next== NULL) {
            return head;
        }
        ListNode* tail = head;
        ListNode* cur = head->next;
        tail->next= NULL;
        while(cur != NULL) {
            ListNode* next= cur->next;
            cur->next = tail;
            tail = cur;
            cur = next;
        }
        return tail;
    }
};
// @lc code=end

