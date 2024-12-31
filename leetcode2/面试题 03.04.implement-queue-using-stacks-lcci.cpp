/*
 * @lc app=leetcode.cn id=面试题 03.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.04] 化栈为队
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
class MyQueue {
public:
    stack<int> left, right;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }

    void move(stack<int>& from, stack<int>& to, int remain = 0) {
        while (from.size() > remain) {
            to.push(from.top());
            from.pop();
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        left.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        move(left, right, 1);
        int val = left.top();
        left.pop();
        move(right, left);
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        move(left, right, 1);
        int val = left.top();
        move(right, left);
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return left.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end



