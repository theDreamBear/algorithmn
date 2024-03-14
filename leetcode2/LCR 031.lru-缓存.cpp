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
    int capacity;
    struct Node {
        int key, value;
    };
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
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



