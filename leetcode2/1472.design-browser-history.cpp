/*
 * @lc app=leetcode.cn id=1472 lang=cpp
 * @lcpr version=30204
 *
 * [1472] 设计浏览器历史记录
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class BrowserHistory {
public:
    map<int, string> his;
    int pos = 0;

    BrowserHistory(string homepage) {
        his[pos] = homepage;
    }
    
    void visit(string url) {
        his[++pos] = url;
        int x = pos + 1;
        while (his.contains(x)) {
            his.erase(x++);
        }
    }
    
    string back(int steps) {
        if (pos + 1 <= steps) {
            pos = 0;
        } else {
            pos -= steps;
        }
        return his[pos];
    }
    
    string forward(int steps) {
        while (steps > 0 and his.contains(pos + 1)) {
            steps--;
            pos++;
        }
        return his[pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end



/*
// @lcpr case=start
// ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"][["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]\n
// @lcpr case=end

 */

