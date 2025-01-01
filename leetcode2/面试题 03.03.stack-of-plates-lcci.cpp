/*
 * @lc app=leetcode.cn id=面试题 03.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.03] 堆盘子
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class StackOfPlates {
public:
    map<int, stack<int>> ds;
    int cap;
    int idx = 0;

    StackOfPlates(int cap) {
        this->cap = cap;
    }
    
    void push(int val) {
        if (idx > ds.size()) {
            ds[++idx];
        }
        ds[idx].push(cap);
        if (ds[idx].size() == cap) {
            ++idx;
        }
    }
    
    int pop() {
        while (idx)
    }
    
    int popAt(int index) {
        
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */
// @lc code=end



/*
// @lcpr case=start
// ["StackOfPlates", "push", "push", "popAt", "pop", "pop"][[1], [1], [2], [1], [], []]\n
// @lcpr case=end

// @lcpr case=start
// ["StackOfPlates", "push", "push", "push", "popAt", "popAt", "popAt"][[2], [1], [2], [3], [0], [0], [0]]\n
// @lcpr case=end

 */

