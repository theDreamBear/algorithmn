/*
 * @lc app=leetcode.cn id=LCR 168 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 168] 丑数
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
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 1) {
            return 1;
        }
        priority_queue<long long, vector<long long>, greater<>> m;
        set<long long> ex;
        m.push(1);
        ex.insert(1);
        while (!m.empty()) {
            int v = m.top();
            m.pop();
            if (--n == 0) {
                return v;
            }
            if (ex.count(2ll * v) == 0) {
                m.push(2ll * v);
                ex.insert(2ll * v);
            }
            if (ex.count(3ll * v) == 0) {
                m.push(3ll * v);
                ex.insert(3ll * v);
            }
            if (ex.count(5ll * v) == 0) {
                m.push(5ll * v);
                ex.insert(5ll * v);
            }
        }
        return 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

