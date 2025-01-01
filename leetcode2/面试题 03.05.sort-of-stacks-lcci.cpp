/*
 * @lc app=leetcode.cn id=面试题 03.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 03.05] 栈排序
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
class SortedStack {
public:
    stack<int> st;
    SortedStack() {
        
    }
    
    void push(int val) {
        if (st.empty() or val < st.top()) {
            st.push(val);
        } else {
            int tmp = st.top();
            st.pop();
            push(val);
            st.push(tmp);
        }
    }
    
    void pop() {
        if (!isEmpty())
        st.pop();
    }
    
    int peek() {
        return isEmpty() ? -1 : st.top();
    }
    
    bool isEmpty() {
        return st.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["SortedStack", "push", "push", "peek", "pop", "peek"][[], [1], [2], [], [], []]\n
// @lcpr case=end

// @lcpr case=start
// ["SortedStack", "pop", "pop", "push", "pop", "isEmpty"][[], [], [], [1], [], []]\n
// @lcpr case=end

 */

