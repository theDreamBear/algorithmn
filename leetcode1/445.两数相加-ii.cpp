/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

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
    int len(ListNode *node) {
        int sz = 0;
        while (node) {
            sz++;
            node = node->next;
        }
        return sz;
    }

    void add(ListNode *left, ListNode *right, int dl, int dr, int &carry) {
        if (dl > dr) {
            add(left->next, right, dl - 1, dr, carry);
            left->val += carry;
            carry = left->val / 10;
            left->val %= 10;
            return;
        }
        // 基本
        if (dl == 1) {
            left->val += right->val;
            carry = left->val / 10;
            left->val %= 10;
            return;
        }
        // ==
        if (dl > 1) {
            add(left->next, right->next, dl - 1, dr - 1, carry);
            left->val += +(right->val + carry);
            carry = left->val / 10;
            left->val %= 10;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *left = l1, *right = l2;
        int l, r;
        l = len(l1);
        r = len(l2);
        if (l < r) {
            swap(left, right);
            swap(l, r);
        }
        ListNode *root = new ListNode(0);
        root->next = left;
        l++;
        int carry = 0;
        add(root, right, l, r, carry);
        while (0 == root->val && root->next) {
            root = root->next;
        }
        return root;
    }
};
// @lc code=end

