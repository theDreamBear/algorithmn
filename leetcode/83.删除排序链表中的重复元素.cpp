/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (48.43%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    62.7K
 * Total Submissions: 129.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 *
 * 示例 1:
 *
 * 输入: 1->1->2
 * 输出: 1->2
 *
 *
 * 示例 2:
 *
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    ListNode* deleteDuplicates1(ListNode* head) {
        if (head == NULL || head ->next == NULL) {
            return head;
        }
        ListNode* tail = head;
        ListNode* cur = head ->next;
        while(cur) {
            ListNode* next = cur->next;
            if (tail->val != cur->val) {
                tail = cur;
            } else {
                tail->next = next;
                cur->next = NULL;
            }
            cur = next;
        }
        return head;
    }

      ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head ->next == NULL) {
            return head;
        }
        ListNode* next = deleteDuplicates(head->next);
        head->next = next;
        if (head->val == next->val) {
            head->next = next->next;
        }
        return head;
    }
};
// @lc code=end

