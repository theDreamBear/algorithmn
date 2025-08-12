/*
 * @lc app=leetcode.cn id=460 lang=cpp
 * @lcpr version=30204
 *
 * [460] LFU 缓存
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
struct Node {
    int key, cnt, value, dfn;
    Node(int k = 0, int t = 0, int v = 0, int dfn = 0): key(k), cnt(t), value(v), dfn(dfn) {}

    bool operator<(const Node& other) const {
        if (cnt != other.cnt) return cnt > other.cnt;
        return dfn > other.dfn;
    }

    bool operator ==(const Node& other) const {
        return key == other.key and cnt == other.cnt and value == other.value and dfn == other.dfn;
    }

    bool operator !=(const Node& other) const {
        return !(*this == other);
    }
};

class LFUCache1 {
public:
    using pi = Node;
    unordered_map<int, pi> cnt;
    priority_queue<pi, vector<pi>> pq;
    int size, capacity;
    int dfn = 0;
    LFUCache1(int capacity):size(0), capacity(capacity) {}

    int get(int key) {
        if (!cnt.count(key)) {
            return -1;
        }
        ++dfn;
        ++cnt[key].cnt;
        cnt[key].dfn = dfn;
        pq.emplace(cnt[key]);
        return cnt[key].value;
    }

    void put(int key, int value) {
        ++dfn;
        if (cnt.count(key)) {
            cnt[key].cnt++;
            cnt[key].value = value;
            cnt[key].dfn = dfn;
            pq.emplace(cnt[key]);
            return;
        }
        // 新增加
        if (size >= capacity) {
            // 删除最小的
            while(pq.top() != cnt[pq.top().key]) {
                // 说明是无效数据, 可以删掉
                pq.pop();
            }
            cnt.erase(pq.top().key);
            pq.pop();
        }
        if (size < capacity) {
            size++;
        }
        cnt[key] = Node(key, 1, value, dfn);
        pq.push(cnt[key]);
    }
};


struct Node2 {
    int key, cnt, value;
    Node2(int k = 0, int t = 0, int v = 0): key(k), cnt(t), value(v) {}
};

class LFUCache2 {
private:
    void erase_element(int key) {
        int t = kv[key]->cnt;
        cnt[t].erase(kv[key]);
        // 链表空了
        if (cnt[t].size() == 0) {
            cnt.erase(t);
        }
        // 删除kv
        kv.erase(key);
    }

    void insert_element(Node2 node) {
        node.cnt++;
        cnt[node.cnt].push_front(node);
        kv[node.key] = cnt[node.cnt].begin();
    }

    void update(int key, int value) {
        auto node = *kv[key];
        node.value = value;

        erase_element(key);
        insert_element(node);
    }

public:
    using pi = Node2;
    int size, capacity;
    map<int, list<pi>> cnt;
    unordered_map<int, list<pi>::iterator> kv;

    LFUCache2(int capacity):size(0), capacity(capacity) {}

    int get(int key) {
        if (!kv.count(key)) {
            return -1;
        }
        update(key, kv[key]->value);
        return kv[key]->value;
    }

    void put(int key, int value) {
        if (kv.count(key)) {
            update(key, value);
            return;
        }
        if (size >= capacity) {
            // 删除最小的 back
            erase_element(cnt.begin()->second.back().key);
        }
        if (size < capacity) {
            size++;
        }
        insert_element(Node2(key, 1, value));
    }
};

struct DN{
    DN* pre, *next;
    int key, val, freq;

    DN(int k = 0, int v = 0, int freq = 0): key(k), val(v), freq(freq), pre(nullptr), next(nullptr){}
};

struct DList {
    DN dummy;

    DList() {
        dummy.pre = &dummy;
        dummy.next = &dummy;
    }

    void push_front(DN* node) {
        node->next = dummy.next;
        dummy.next->pre = node;

        node->pre = &dummy;
        dummy.next = node;
    }

    DN* pop_back() {
        DN* node = tail();
        erase(node);
        return node;
    }

    DN* tail() {
        return dummy.pre;
    }

    bool empty() {
        return tail() == &dummy;
    }

    void erase(DN* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

};

class LFUCache {
private:
    unordered_map<int, DList> freq_to_node;

    unordered_map<int, DN*> key_to_node;

    int minFre = 1;
    int size, capacity;


    DN* get_node(int key) {
        if (!key_to_node.count(key)) {
            return nullptr;
        }
        DN* node = key_to_node[key];
        // 摘掉
        freq_to_node[node->freq].erase(node);
        if (minFre == node->freq and freq_to_node[node->freq].empty()) {
            ++minFre;
        }
        freq_to_node[++node->freq].push_front(node);
        return node;
    }

    void insert(int key, int value) {
        ++size;
        auto node = new DN(key, value, 1);
        key_to_node[node->key] = node;
        freq_to_node[1].push_front(node);
    }

    void remove_if() {
         if (size > capacity) {
            // 删除
            auto dn = freq_to_node[minFre].pop_back();
            key_to_node.erase(dn->key);
            --size;
        }
    }

public:

    LFUCache(int capacity):size(0), capacity(capacity) {}

    int get(int key) {
        auto node = get_node(key);
        return node ? node->val : -1;
    }

    void put(int key, int value) {
        if (key_to_node.count(key)) {
            get_node(key)->val = value;
            return;
        }
        insert(key, value);
        remove_if();
        minFre = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"][[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]\n
// @lcpr case=end

 */

