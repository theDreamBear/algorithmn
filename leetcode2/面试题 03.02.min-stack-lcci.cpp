/*
 * @lc app=leetcode.cn id=面试题 03.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.02] 栈的最小值
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
class MinStack {
public:
    stack<int> val, mm;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        val.push(x);
        if (mm.empty() or x < mm.top()) {
            mm.push(x);
        } else {
            mm.push(mm.top());
        }
    }
    
    void pop() {
        val.pop();
        mm.pop();
    }
    
    int top() {
        return val.top();
    }
    
    int getMin() {
        return mm.top();
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



