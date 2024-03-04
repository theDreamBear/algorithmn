/*
 * @lc app=leetcode.cn id=LCR 184 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 184] 设计自助结算系统
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
class Checkout {
private:
    queue<int> q;
    // 单调递减队列
    deque<int> mq;
public:
    Checkout() {

    }

    int get_max() {
        if (mq.empty()) {
            return -1;
        }
        return mq.front();
    }

    void add(int value) {
        while (!mq.empty() && value > mq.back()) {
            mq.pop_back();
        }
        q.push(value);
        mq.push_back(value);
    }

    int remove() {
        if (q.empty()) {
            return -1;
        }
        int v = q.front();
        q.pop();
        if (mq.front() == v) {
            mq.pop_front();
        }
        return v;
    }
};



/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */
// @lc code=end



/*
// @lcpr case=start
// ["Checkout","add","add","get_max","remove","get_max"][[],[4],[7],[],[],[]]\n
// @lcpr case=end

// @lcpr case=start
// ["Checkout","remove","get_max"][[],[],[]]\n
// @lcpr case=end

 */

