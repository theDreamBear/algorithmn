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
    int nthUglyNumber1(int n) {
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

    bool check(int v, unordered_map<int, bool>& memo) {
        bool flag = true;
        int old = v;
        while (flag) {
            flag = false;
            if (v % 5 == 0) {
                flag = true;
                v /= 5;
                if (memo.count(v)) {
                    return memo[old]  = memo[v];
                }

            }
            if (v % 3 == 0) {
                flag = true;
                v /= 3;
                if (memo.count(v)) {
                    return memo[old]  = memo[v];
                }
            }
            if (v % 2 == 0) {
                flag = true;
                v /= 2;
                if (memo.count(v)) {
                    return memo[old]  = memo[v];
                }
            }
       }
       return memo[old] = v ==  1;
    }

    // 超时
    int nthUglyNumber_violatile(int n) {
        if (n == 1) {
            return 1;
        }
        int ct = 1;
        int v = 2;
        unordered_map<int, bool> memo;
        while (ct < n) {
            if (check(v, memo)) {
                if (++ct == n) {
                    return v;
                }
            }
            v++;
        }
        return 0;
    }

    int nthUglyNumber(int n) {
        if (n == 1) {
            return 1;
        }
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

