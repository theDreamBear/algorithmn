/*
 * @lc app=leetcode.cn id=LCR 154 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 154] 复杂链表的复制
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
// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* node, unordered_map<Node*, Node*>& reflection) {
        if (!node) {
            return NULL;
        }
        if (reflection.count(node)) {
            return reflection[node];
        }
        reflection[node] = new Node(node->val);
        reflection[node]->next = copyRandomList(node->next, reflection);
        reflection[node]->random = copyRandomList(node->random, reflection);
        return reflection[node];
    }

    Node* copyRandomList1(Node* head) {
        unordered_map<Node*, Node*> reflection;
        return copyRandomList(head, reflection);
    }

    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        unordered_map<Node*, Node*> reflection;
        queue<Node*> q;
        reflection[head] = new Node(head->val);
        q.push(head);
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->next) {
                if (!reflection.count(node->next)) {
                    reflection[node->next]= new Node(node->next->val);
                    q.push(node->next);
                }
                reflection[node]->next = reflection[node->next];
            }
            if (node->random) {
                if (!reflection.count(node->random)) {
                    reflection[node->random]= new Node(node->random->val);
                    q.push(node->random);
                }
                reflection[node]->random = reflection[node->random];
            }
        }
        return reflection[head];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */

