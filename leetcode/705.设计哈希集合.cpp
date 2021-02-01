/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
/* 蠢的办法, 慢
    add O(n)
    remove O(n)
    contains O(n)
*/
class MyHashSet1 {
 private:
    vector<int> nums;

    int binary_search(int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int _contains(int target) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

 public:
    /** Initialize your data structure here. */
    MyHashSet1() {
        // 最蠢的方式
        // 超时
    }

    void add(int key) {
        if (contains(key)) {
            return;
        }
        nums.push_back(key);
    }

    void remove(int key) {
        int pos = _contains(key);
        if (pos != -1) {
            swap(nums[pos], nums.back());
            nums.pop_back();
        }
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) { return -1 != _contains(key); }
};

/*
    使用多个桶来加速
    瓶颈在于 contains函数和 remove 函数,
    可以考虑用链表来加速remove

*/
class MyHashSet2 {
 private:
    vector<vector<int>> _hash_bucket;
    int _bucket_num;

    int _hash(int key) { return key % _bucket_num; }

    int _contains(int idx, int target) {
        for (int i = 0; i < _hash_bucket[idx].size(); ++i) {
            if (_hash_bucket[idx][i] == target) {
                return i;
            }
        }
        return -1;
    }

 public:
    /** Initialize your data structure here. */
    MyHashSet2() {
        _bucket_num = 10000;
        _hash_bucket = vector<vector<int>>(_bucket_num);
    }

    void add(int key) {
        int index = _hash(key);
        int pos = _contains(index, key);
        if (pos == -1) {
            _hash_bucket[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = _hash(key);
        int pos = _contains(index, key);
        if (pos == -1) {
            return;
        }
        _hash_bucket[index].erase(_hash_bucket[index].begin() + pos);
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash = _hash(key);
        return -1 != _contains(hash, key);
    }
};

/*
    模拟位图
*/
class MyHashSet3 {
 private:
    vector<unsigned long long> buffer;

    int _index(int key) { return key / 64; }

    int _bitPos(int key) { return key % 64; }

 public:
    /** Initialize your data structure here. */
    MyHashSet3() {}

    void add(int key) {
        int index = _index(key);
        int pos = _bitPos(key);
        if (index >= buffer.size()) {
            int len = buffer.size();
            buffer.resize(index + 1);
            for (int i = len; i < buffer.size(); ++i) {
                buffer[i] = 0;
            }
        }
        buffer[index] |= ((unsigned long long)0x1 << pos);
    }

    void remove(int key) {
        int index = _index(key);
        int pos = _bitPos(key);
        if (index >= buffer.size()) {
            return;
        }
        buffer[index] &= ~((unsigned long long)0x1 << pos);
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = _index(key);
        if (index >= buffer.size()) {
            return false;
        }
        return buffer[index] & ((unsigned long long)0x1 << _bitPos(key));
    }
};


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
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
