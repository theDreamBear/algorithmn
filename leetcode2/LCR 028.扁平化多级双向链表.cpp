/*
 * @lc app=leetcode.cn id=LCR 028 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 028] 扁平化多级双向链表
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

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    /*
        节点不是真正的双向链表
        头节点的 pre 为空
        尾节点的 next也为空
    */
    Node* flatten_bad(Node* head) {
        if (!head) {
            return head;
        }
        Node* next = head->next;
        if (next != head) {
            // 保证next 是一个双向链表
            next->prev = head->prev;
            head->prev->next = next;

            head->next = head;
            head->prev = head;
        }

        if (head->child) {
            auto fc = flatten(head->child);
            Node* nt = fc->prev;
            head->next = fc;
            fc->prev = head;
            head->prev = nt;
            nt->next = head;
        }

        if (next != head) {
            auto fc = flatten(next);
            Node* nt = fc->prev;

            head->prev->next = fc;
            fc->prev = head->prev;

            nt->next = head;
            head->prev = nt;
        }
        return head;
    }

    Node* flatten_1(Node* head) {
        if (!head) {
            return head;
        }
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* next = cur->next;

                Node* p = cur->child;
                Node* pt = p;
                while (pt->next) {
                    pt = pt->next;
                }

                cur->next = p;
                p->prev = cur;

                if (next) {
                    pt->next = next;
                    next->prev = pt;
                }
                // 需要重置child, 这一步容易遗漏
                cur->child = nullptr;
            }
            cur = cur->next;
        };
        return head;
    }

    pair<Node*, Node*> flattenHelper(Node* head) {
        if (!head) {
            return {head, head};
        }
        Node* cur = head;
        while (cur && !cur->child) {
            if (cur->next) {
                cur = cur->next;
            } else {
                break;
            }
        }
        if (!cur->child) {
            return {head, cur};
        }
        auto [ch, ct] = flattenHelper(cur->child);
        auto [nh, nt] = flattenHelper(cur->next);
        cur->child = NULL;
        // 后序遍历
        cur->next = ch;
        ch->prev = cur;
        if (nh) {
            ct->next = nh;
            nh->prev = ct;
        }
        return {head, nh ? nt : ct};
    }

    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        flattenHelper(head);
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,null,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

