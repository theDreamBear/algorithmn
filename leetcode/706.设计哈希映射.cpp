/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
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

using namespace std;

// @lc code=start
class MyHashSet {
 private:
    bitset<1000001> bit;

 public:
    /** Initialize your data structure here. */
    MyHashSet() {}

    void add(int key) {
        bit.set(key, 1);
    }

    void remove(int key) {
        bit[key] = 0;
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return bit[key];
    }
};

/*
    使用 hashset加速查找
*/
class MyHashMap {
private:
    MyHashSet hashset;
    vector<vector<pair<int, int>>> _buckets;
    int _buck_nums;

    int _index(int key) {
        return key % _buck_nums;
    }

    pair<int, int>& _getPair(int index, int key) {
        for (auto& kv : _buckets[index]) {
            if (kv.first == key) {
                return kv;
            }
        }
        return _buckets[index][0];
    }
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        _buck_nums = 100;
        _buckets = vector<vector<pair<int, int>>>(_buck_nums);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = _index(key);
        if (!hashset.contains(key)) {
            _buckets[index].emplace_back(key, value);
            hashset.add(key);
        } else {
            auto& p = _getPair(index, key);
            p.second = value;
        }
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (!hashset.contains(key)) {
            return -1;
        }
        int index = _index(key);
        return _getPair(index, key).second;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        if(!hashset.contains(key)) {
            return;
        }
        hashset.remove(key);
        int index = _index(key);
        for (auto it = _buckets[index].begin(); it != _buckets[index].end(); it++) {
            if (it->first == key) {
                _buckets[index].erase(it);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

