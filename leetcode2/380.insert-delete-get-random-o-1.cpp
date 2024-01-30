/*
 * @lc app=leetcode.cn id=380 lang=cpp
 * @lcpr version=30114
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */


// @lcpr-template-start
#include <cstdlib>
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
class RandomizedSet {
private:
    int data[200001];
    unordered_map<int, int> indexes;
    int sz = 0;


    void update(int val, int pos) {
        data[pos] = val;
        indexes[val] = pos;
    }

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (indexes.count(val)) {
            return false;
        }
        update(val, sz);
        sz++;
        return true;
    }

    bool remove(int val) {
        if (indexes.count(val)) {
            int p = indexes[val];
            if (p + 1 != sz) {
                int lv = data[sz - 1];
                update(lv, p);
            }
            --sz;
            indexes.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() {
        int idx = random() % sz;
        return data[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end



