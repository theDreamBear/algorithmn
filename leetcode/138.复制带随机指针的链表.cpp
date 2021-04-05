/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
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
    /*
        hash
    */
    Node* copyRandomList1(Node* head) {
        if (head == NULL) {
            return head;
        }
        unordered_map<Node*, Node*> hash;
        Node* cur = head;
        while (cur) {
            Node* temp = new Node(cur->val);
            hash[cur] = temp;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->next) {
                hash[cur]->next = hash[cur->next];
            }
            if (cur->random) {
                hash[cur]->random = hash[cur->random];
            }
            cur = cur->next;
        }
        return hash[head];
    }

    /*
        hash + 递归
    */
    Node* copyListNode(Node* node, unordered_map<Node*, Node*>& hash) {
        if (!node) {
            return NULL;
        }
        if (hash.count(node) > 0) {
            return hash[node];
        }
        Node* newNode = new Node(node->val);
        hash[node] = newNode;

        newNode->next = copyListNode(node->next, hash);
        newNode->random = copyListNode(node->random, hash);
        return newNode;
    }

    Node* copyRandomList2(Node* head) {
        unordered_map<Node*, Node*> hash;
        return copyListNode(head, hash);
    }


    /*
        O(1) 空间复杂度
    */
    Node* copyRandomList(Node* head) {
        if (!head) {
            return head;
        }
        Node* cur = head;
        while (cur) {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        Node* old = head;
        Node* newHead = head->next;
        Node* n = head->next;
        while (old) {
            old->next = n->next;
            old = old->next;
            n->next = (old) ? old->next : nullptr;
            n = n->next;
        }
        return newHead;
    }
};
// @lc code=end
