/*
 * @lc app=leetcode.cn id=LCR 147 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 147] 最小栈
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
class MinStack1 {
private:
    stack<int> st, mst;
public:
    /** initialize your data structure here. */
    MinStack1() {}

    void push(int x) {
        st.push(x);
        if (mst.empty() or mst.top() > x) {
            mst.push(x);
        } else {
            mst.push(mst.top());
        }
    }

    void pop() {
        st.pop();
        mst.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mst.top();
    }
};


class MinStack_vi {
private:
    stack<int> st;
public:
    /** initialize your data structure here. */
    MinStack_vi() {}

    void push(int x) {
        st.push(x);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        stack<int> mst;
        int mm = st.top();
        while (!st.empty()) {
            if (mm > st.top()) {
                mm = st.top();
            }
            mst.push(st.top());
            st.pop();
        }
        while (!mst.empty()) {
            st.push(mst.top());
            mst.pop();
        }
        return mm;
    }
};

class MinStack {
private:
    stack<int> st;
    // 单点不增栈
    stack<int> mst;
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        st.push(x);
        if (mst.empty() || x <= mst.top()) {
            mst.push(x);
        }
    }

    void pop() {
        int v = st.top();
        st.pop();
        if (mst.top() == v) {
            mst.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mst.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[2],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

