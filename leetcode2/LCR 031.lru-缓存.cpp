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
            int val;
            Node* next;

            Node(int val):val(), next(nullptr){}
        };

        Node dummy;
        unordered_map<int, Node*> hash;

        HashList(int capacity):capacity(capacity) {
            sz = 0;
        }

        int get(int key) {
            if (!hash.count(key)) {
                return -1;
            }
            Node* pre = hash[key];
            Node* now = pre->next;
            // 摘除now
            pre->next = pre->next->next;
            // 头插
            now->next = dummy.next;
            dummy.next = now;
            return now->val;
        }

        void put(int key, int value) {
            if (!hash.count(key)) {
                hash[key] = new Node(value);
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



