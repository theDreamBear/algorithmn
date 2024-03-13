/*
 * @lc app=leetcode.cn id=LCR 030 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 030] O(1) 时间插入、删除和获取随机元素
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
class RandomizedSet {
private:
    vector<int> _d;
    unordered_map<int, int> data;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data.count(val)) {
            return false;
        }
        data[val] = _d.size();
        _d.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!data.count(val)) {
            return false;
        }
        // if (data.size() != 1) {
        //     int p = data[val];
        //     if (p + 1 != _d.size()) {
        //         swap(_d[p], _d.back());
        //         data[_d[p]] = p;
        //     }
        // }

        int index = data[val];
        int last = _d.back();
        _d[index] = last;
        data[last] = index;
        
        data.erase(val);
        _d.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return _d[random() % _d.size()];
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



/*
// @lcpr case=start
// ["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"][[], [1], [2], [2], [], [1], [2], []]\n
// @lcpr case=end

 */

