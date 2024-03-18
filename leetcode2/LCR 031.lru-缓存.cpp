/*
 * @lc app=leetcode.cn id=LCR 031 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 031] LRU 缓存
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
class LRUCache {
private:

    struct HashList {
        int capacity, sz;
        struct Node {
            int key;
            int val;
            Node* next;

            Node(int key = -1, int val = -1):val(), next(nullptr){}
        };

        Node dummy;
        Node *tail;
        unordered_map<int, Node*> hash;

        HashList(int capacity):capacity(capacity) {
            sz = 0;
            tail = &dummy;
        }

        void update(Node* node, Node* next) {
            node->next = next->next;
            if (node->next) {
                hash[node->next->key] = node;
            }
        }

        int get(int key) {
            if (!hash.count(key)) {
                return -1;
            }
            if (sz == 1) {
                return hash[key]->val;
            }
            Node* pre = hash[key];
            Node* now = pre->next;
            // 摘除now
            update(pre, now);
            // 头插
            update(now, &dummy);

            // 更新now
            dummy.next = now;
            hash[key] = &dummy;
            if (now == tail) {
                tail = pre;
            }
            return now->val;
        }

        void put(int key, int value) {
            if (!hash.count(key)) {
                hash[key] = new Node(value);
                
            } else {

            }
        }
    };

public:
    LRUCache(int capacity) {

    }

    int get(int key) {

    }

    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



