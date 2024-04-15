/*
 * @lc app=leetcode.cn id=LCR 041 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 041] 数据流中的移动平均值
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
class MovingAverage1 {
    queue<int> q;
    int sz;
    int preSum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage1(int size) {
        sz = size;
    }

    double next(int val) {
        preSum += val;
        q.push(val);
        if (q.size() > sz) {
            preSum -= q.front();
            q.pop();
        }
        return preSum * 1.0 / q.size();
    }
};


class CycleArray {
 private:
    vector<int> data;
    int nextPost = 0;
    int preSum = 0;

 public:
    CycleArray(int capacity): data(capacity){}

    double next(int val) {
        preSum += val;
        int idx = nextPost++ % data.size();
        preSum -= data[idx];
        data[idx] = val;
        return preSum * 1.0 / min((int)data.size(), nextPost);
    }
};

class MovingAverage {
    CycleArray arr;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): arr(size){}

    double next(int val) {
        return arr.next(val);
    }
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MovingAverage", "next", "next", "next"\n[[3], [1], [10], [3], [5]]\n
// @lcpr case=end

 */

