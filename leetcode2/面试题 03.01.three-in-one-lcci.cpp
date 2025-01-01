/*
 * @lc app=leetcode.cn id=面试题 03.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.01] 三合一
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
class TripleInOne {
public:
    vector<int> st;
    vector<tuple<int, int, int>> seg;
    TripleInOne(int stackSize) {
        st.resize(stackSize * 3);
        seg.resize(3);
        seg[0] = {0, 0, stackSize - 1};
        seg[1] = {stackSize, stackSize, stackSize * 2 - 1};
        seg[2] = {stackSize * 2, stackSize * 2, stackSize * 3 - 1};
    }
    
    void push(int stackNum, int value) {
        auto& [left, top, right] = seg[stackNum];
        if (top <= right) {
            st[top++] = value;
        }
    }
    
    int pop(int stackNum) {
        auto& [left, top, right] = seg[stackNum];
        if (top == left) return -1;
        return st[--top];
    }
    
    int peek(int stackNum) {
        auto& [left, top, right] = seg[stackNum];
        if (top == left) return -1;
        return st[top - 1];
    }
    
    bool isEmpty(int stackNum) {
        auto& [left, top, right] = seg[stackNum];
        return left == top;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
// @lc code=end



/*
// @lcpr case=start
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"][[1], [0, 1], [0, 2], [0], [0], [0], [0]]\n
// @lcpr case=end

// @lcpr case=start
// ["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"][[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]\n
// @lcpr case=end

 */

