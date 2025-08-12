/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30204
 *
 * [146] LRU 缓存
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
#include <list>
// @lcpr-template-end
// @lc code=start
class LRUCache1 {
public:
    unordered_map<int, list<pair<int, int>>::iterator> hs;
    list<pair<int, int>> cache;
    int capacity;
    int size;
    LRUCache1(int capacity): capacity(capacity), size(0) {

    }

    int get(int key) {
        if (!hs.count((key))) return -1;
        int ans = hs[key]->second;

        // 删除cahce
        cache.erase(hs[key]);
        // 提高头部
        cache.push_front({key, ans});
        // 更新迭代器
        hs[key] = cache.begin();
        return ans;
    }

    void put(int key, int value) {
        if (hs.count(key)) {
            // 删除cahce
            cache.erase(hs[key]);
            // 提高头部
            cache.push_front({key, value});
            // 更新迭代器
            hs[key] = cache.begin();
            return;
        }
        if (size >= capacity) {
            // 删除尾部
            auto [dk, _] = cache.back();
            hs.erase(dk);
            cache.pop_back();
        }
        if (size < capacity) size++;
        cache.push_front({key, value});
        // 更新迭代器
        hs[key] = cache.begin();
    }
};

struct Node {
    Node* pre, *next;
    int key, val;

    Node(int key = -1, int val = -1):key(key), val(val), pre(nullptr), next(nullptr){}
};

struct DN {

    Node root;

    DN() {
        root.pre = root.next = &root;
    }

    void push_front(int key, int val) {
        Node* node = new Node(key, val);

        node->next = root.next;
        root.next->pre = node;

        root.next = node;
        node->pre = &root;
    }

    void erase(Node* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    Node* begin() {
        return root.next;
    }

    Node* back() {
        return root.pre;
    }
};


class LRUCache {
public:
    unordered_map<int, Node*> hs;
    DN cache;
    int capacity;
    int size;
    LRUCache(int capacity): capacity(capacity), size(0) {

    }

    int get(int key) {
        if (!hs.count((key))) return -1;
        int ans = hs[key]->val;

        // 删除cahce
        cache.erase(hs[key]);
        // 提高头部
        cache.push_front(key, ans);
        // 更新迭代器
        hs[key] = cache.begin();
        return ans;
    }

    void put(int key, int value) {
        if (hs.count(key)) {
            // 删除cahce
            cache.erase(hs[key]);
            // 提高头部
            cache.push_front(key, value);
            // 更新迭代器
            hs[key] = cache.begin();
            return;
        }
        if (size >= capacity) {
            // 删除尾部
            auto dk = cache.back()->key;
            hs.erase(dk);
            cache.erase(cache.back());
        }
        if (size < capacity) size++;
        cache.push_front(key, value);
        // 更新迭代器
        hs[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



