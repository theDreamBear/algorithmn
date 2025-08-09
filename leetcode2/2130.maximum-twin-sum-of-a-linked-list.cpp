/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 * @lcpr version=30204
 *
 * [2130] 链表最大孪生和
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

namespace My_List {
    /*
    1. 链表长度: size
    2. 翻转链表: reverse
    3. kth
    4. kth pre
    5. left mid
    6. right mid
    */
    int size(ListNode *node) {
        if (!node) return 0;
        ListNode *cur = node;
        int len = 0;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        return len;
    }

    // 翻转链表
    ListNode *reverse(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *pre = nullptr, *cur = node;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    // 查找第k个链表节点
    ListNode *find_kth(ListNode *node, int k) {
        ListNode *cur = node;
        while (--k and cur) {
            cur = cur->next;
        }
        assert(k == 0);
        return cur;
    }

    ListNode *find_kth_pre(ListNode *node, int k) {
        // k = 1, 头结点没有pre
        assert(k > 1);
        return find_kth(node, k - 1);
    }

    // 查找右mid
    ListNode *find_right_mid(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *slow = node, *fast = node;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        return slow;
    }

    ListNode *find_right_mid2(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        int sz = size(node);
        return find_kth(node, sz / 2 + 1);
    }

    // 查找左mid
    ListNode *find_left_mid(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        ListNode *slow = node, *fast = node->next;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        return slow;
    }

    ListNode *find_left_mid2(ListNode *node) {
        if (!node or !node->next) {
            return node;
        }
        int sz = size(node);
        return find_kth(node, (sz + 1) / 2);
    }

    struct List {
        ListNode *head = nullptr, *tail = nullptr;
    };

    List NodeToList(ListNode *node) {
        List list;
        list.head = node;
        ListNode *cur = node;
        while (cur->next) {
            cur = cur->next;
        }
        list.tail = cur;
        return list;
    }


    List reverseList(List &list) {
        if (!list.head) return list;
        List tmp = list;
        reverse(list.head);
        swap(tmp.head, tmp.tail);
        return tmp;
    }


};

using namespace My_List;

class Solution {
public:
    int pairSum(ListNode* head) {
        if (!head) return 0;
        if (!head->next) return head->val;
        auto l =  find_left_mid(head);
        auto r = l->next;
        l->next = nullptr;
        auto h2 = reverse(r);
        int ans = 0;
        while (head and h2) {
            ans = max(ans, (head->val + h2->val));
            head = head->next;
            h2 = h2->next;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,100000]\n
// @lcpr case=end

 */

