/*
 * @lc app=leetcode.cn id=705 lang=cpp
 * @lcpr version=30122
 *
 * [705] 设计哈希集合
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
#include <list>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyHashSet1 {
public:
    class MH{
    public:
        const static int sz = 769;
        vector<list<int>> data;

        MH():data(sz){}

        void add(int key) {
            int idx = key % sz;
            if (!contains(key)) {
                data[idx].push_back(key);
            }
        }

        bool contains(int key) {
            int idx = key % sz;
            return find(data[idx].begin(), data[idx].end(), key) != data[idx].end();
        }

        void remove(int key) {
            int idx = key % sz;
            data[idx].remove(key);
        }
    };

    MH mh;
    MyHashSet1() {

    }

    void add(int key) {
        mh.add(key);
    }

    void remove(int key) {
        mh.remove(key);
    }

    bool contains(int key) {
        return mh.contains(key);
    }
};

class MyHashSet2 {
public:
    vector<int> data;

    MyHashSet2():data(1e6 + 1) {

    }

    void add(int key) {
        data[key] = 1;
    }

    void remove(int key) {
        data[key] = 0;
    }

    bool contains(int key) {
        return data[key] == 1;
    }
};

class MyHashSet {
public:
    constexpr static int sz = 1e6 + 1;
   bitset<sz> data;

    MyHashSet() {

    }

    void add(int key) {
        data.set(key);
    }

    void remove(int key) {
        if (contains(key)) {
            data.flip(key);
        }
    }

    bool contains(int key) {
        return data.test(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"][[], [1], [2], [1], [3], [2], [2], [2], [2]]\n
// @lcpr case=end

 */

