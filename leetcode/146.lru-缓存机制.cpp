/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

// @lc code=start
class LRUCache {
public:
    struct hashList {
        struct ListNode {
            int key;
            int val;
            ListNode *pre, *next;

            ListNode(int key, int val):key(key),val(val), pre(nullptr), next(nullptr) {}

            ListNode() : ListNode(-1, -1) {}
        };

        int capacity;
        int sz;
        ListNode root;
        ListNode* tail;

        unordered_map<int, ListNode*> hash;

        hashList(int capacity) : capacity(capacity), sz(0) {
            tail = &root;
        }

        void removeNode(ListNode* node) {
            if (node->next) {
                node->pre->next = node->next;
                node->next->pre = node->pre;
            }
        }

        void push_back(ListNode* node) {
            node->pre = tail;
            tail->next = node;
            node->next = nullptr;
            tail = node;
        }

        int get(int key) {
            if (hash.count(key) > 0) {
                // 访问时将节点置于末尾
                ListNode* node = hash[key];
                if (node->next) {
                    removeNode(node);
                    push_back(node);
                }
                return hash[key]->val;
            }
            return -1;
        }

        void put(int key, int val) {
            if (hash.count(key) > 0) {
                // 访问时将节点置于末尾
                ListNode* node = hash[key];
                node->val = val;
                if (!node->next) {
                    return;
                }
                removeNode(node);
                push_back(node);
                return;
            }
            if (sz < capacity) {
                ListNode* node = new ListNode(key, val);
                push_back(node);
                hash[key] = node;
                ++sz;
                return;
            }
            // 替换
            ListNode* node = root.next;
            hash.erase(node->key);
            node->key = key;
            node->val = val;
            hash[key] = node;
            removeNode(node);
            push_back(node);
        }

        ~hashList() {
            ListNode* cur = root.next;
            while (cur) {
                ListNode* next = cur->next;
                delete cur;
                cur = next;
            }
        }
    };

    hashList list;

    LRUCache(int capacity) : list(capacity) {
    }

    int get(int key) {
        return list.get(key);
    }

    void put(int key, int value) {
        list.put(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

