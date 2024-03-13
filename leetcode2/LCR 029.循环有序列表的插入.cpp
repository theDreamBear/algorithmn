/*
 * @lc app=leetcode.cn id=LCR 029 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 029] 循环有序列表的插入
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
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        auto node = new Node(insertVal);
        if (!head || head->next == head) {
            node->next = head;
            if (head) {
                head->next = node;
            } else {
                node->next = node;
            }
            return head ? head : node;
        }
        Node* cur = head, *next = head->next;
        while(next != head) {
            // 上升阶段
            if (cur->val <= insertVal and insertVal <= next->val) {
                break;
            } else if (cur->val > next->val) {
                // 跳崖阶段
                if (insertVal >= cur->val || insertVal <= next->val) {
                   break;
                }
            }
            cur = next;
            next = next->next;
        }
        cur->next = node;
        node->next = next;
        return head;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,4,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

