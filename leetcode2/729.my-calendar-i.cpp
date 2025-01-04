/*
 * @lc app=leetcode.cn id=729 lang=cpp
 * @lcpr version=30204
 *
 * [729] 我的日程安排表 I
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
class MyCalendar {
public:
    map<int, int> cal;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = cal.lower_bound(startTime);
        if (it != cal.end()) {
            // [startTime, endTime)
            if (it->first < endTime) {
                return false;
            }
        }
        if (it != cal.begin()) {
            it = prev(it);
            // [first, secod)
            if (startTime < it->second) {
                return false;
            }
        }
        cal[startTime] = endTime;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendar", "book", "book", "book"][[], [10, 20], [15, 25], [20, 30]]\n
// @lcpr case=end

 */

