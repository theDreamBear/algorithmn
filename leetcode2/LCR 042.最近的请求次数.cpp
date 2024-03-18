/*
 * @lc app=leetcode.cn id=LCR 042 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 042] 最近的请求次数
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
class RecentCounter {
private:
    // 滑动窗口
    int sz = 0;
    queue<int> q;
public:
    RecentCounter() {

    }

    int ping(int t) {
        ++sz;
        q.push(t);
        while (!q.empty() and q.front() + 3000 < t) {
            --sz;
            q.pop();
        }
        return sz;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end



/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping"\n[[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */

