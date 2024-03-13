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
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        Node* next = head->next;
        if (next and next != head) {
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

        if (next and next != head) {
            auto fc = flatten(next);
            Node* nt = fc->prev;

            head->prev->next = fc;
            fc->prev = head->prev;

            nt->next = head;
            head->prev = nt;
        }
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

