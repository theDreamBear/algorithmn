/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
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
// struct ListNode {
//     ListNode(int val = 0, ListNode* next = nullptr):val(val), next(next){}
// };


class MyLinkedList {
private:
    ListNode* findPre(int index) {
        ListNode* cur = &dummy;
        while (index-- > 0 and cur) {
            cur = cur->next;
        }
        if (index > 0) return nullptr;
        return cur;
    }


public:
    ListNode dummy;
    ListNode* tail;
    int size;


    MyLinkedList() {
        tail = &dummy;
        size = 0;
    }

    int get(int index) {
        if (index >= size) return -1;
        return findPre(index)->next->val;
    }

    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummy.next;
        dummy.next = node;

        // 维护
        if (tail->next == node) {
            tail = tail->next;
        }
        size++;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        tail->next = node;
        tail = tail->next;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;
        auto pre = findPre(index);
        ListNode* node = new ListNode(val);
        node->next = pre->next;
        pre->next = node;

        //
        if (tail->next == node) tail = node;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;
        auto pre = findPre(index);
        // 最后一个
        pre->next = pre->next->next;

        // 维护
        if (pre->next == nullptr) {
            tail = pre;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end



