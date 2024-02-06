/*
 * @lc app=leetcode.cn id=LCR 125 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 125] 图书整理 II
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
class CQueue {
private:
    stack<int> psh_stk, pp_stk;
public:
    CQueue() {

    }

    void appendTail(int value) {
        psh_stk.push(value);
    }

    int deleteHead() {
        if (psh_stk.empty()) {
            return -1;
        }
        while (psh_stk.size() > 1) {
            pp_stk.push(psh_stk.top());
            psh_stk.pop();
        }
        int val = psh_stk.top();
        psh_stk.pop();
        while (!pp_stk.empty()) {
            psh_stk.push(pp_stk.top());
            pp_stk.pop();
        }
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
// @lc code=end



/*
// @lcpr case=start
// ["BookQueue", "push", "push", "pop"][[], [1], [2], []]\n
// @lcpr case=end

 */

