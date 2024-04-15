/*
 * @lc app=leetcode.cn id=706 lang=cpp
 * @lcpr version=30122
 *
 * [706] 设计哈希映射
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
#include <list>
// @lcpr-template-end
// @lc code=start
class MyHashMap1 {
private:
    int data[1000001];
public:
    MyHashMap1() {
        memset(data, -1, sizeof(data));
    }

    void put(int key, int value) {
        data[key] = value;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

class MyHashMap {
private:
    vector<list<pair<int, int>>> data;
public:
    MyHashMap(): data(1023) {
    }

    list<pair<int, int>>::iterator getIte(int key) {
        int idx = key % 1023;
        return find_if(data[idx].begin(), data[idx].end(), [&](const pair<int, int>& p) {
            return p.first == key;
        });
    }

    void put(int key, int value) {
        auto it = getIte(key);
        int idx = key % 1023;
        if (it == data[idx].end()) {
            data[idx].push_back({key, value});
        } else {
            it->second = value;
        }
    }

    int get(int key) {
        auto it = getIte(key);
        int idx = key % 1023;
        if (it == data[idx].end()) {
            return -1;
        }
        return it->second;
    }

    void remove(int key) {
        auto it = getIte(key);
        int idx = key % 1023;
        if (it != data[idx].end()) {
            data[idx].erase(it);
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



/*
// @lcpr case=start
// ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"][[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n
// @lcpr case=end

 */

