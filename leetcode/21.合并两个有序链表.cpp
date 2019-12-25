/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.76%)
 * Likes:    771
 * Dislikes: 0
 * Total Accepted:    156.4K
 * Total Submissions: 266K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(0) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == 0) {
            return l2;
        }
        if (l2 == 0) {
            return l1;
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            ListNode* lnext;
            if (l1->val <= l2->val) {
                tail->next = l1;
                tail = tail->next;
                lnext = l1->next;
                tail->next= 0;
                l1 = lnext;
            } else {
                tail->next = l2;
                tail = tail->next;
                lnext = l2->next;
                tail->next = 0;
                l2 = lnext;
            }
        }
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }
        return dummy.next;
    }
};
// @lc code=end

