/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
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
class KthLargest {
 private:
    // 默认是大顶堆
    priority_queue<int, vector<int>, greater<int>> minheap;
    int _k;

    void _add(int val) {
        minheap.push(val);
        if (minheap.size() > _k) {
            minheap.pop();
        }
    }

 public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (auto v : nums) {
            _add(v);
        }
    }

    int add(int val) {
        _add(val);
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
