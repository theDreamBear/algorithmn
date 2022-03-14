/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */
 #include <iostream>
 #include <utility>
 #include <string>
 #include <string.h>
 #include <vector>
 #include <map>
 #include <set>
 #include <stack>
 #include <queue>
 #include <unordered_map>
 #include <unordered_set>
 #include <algorithm>
 #include <numeric>

 using namespace std;

// @lc code=start
class Solution {
 public:
    bool fz(int n, const vector<int> &exist) {
        for (; n != 1;) {
            int i = 0;
            for (; i < exist.size(); i++) {
                if (n % exist[i] == 0) {
                    n /= exist[i];
                    break;
                }
                if (n < exist[i]) {
                    return false;
                }
            }
            if (i >= exist.size()) {
                return false;
            }
        }
        return true;
    }

    // 方法一暴力枚举
    int nthSuperUglyNumber0(int n, vector<int> &primes) {
        if (n == 1) {
            return 1;
        }
        int ct = 1;
        int cur = 2;
        for (;;) {
            if (fz(cur, primes)) {
                if (++ct == n) {
                    break;
                }
            }
            ++cur;
        }
        return cur;
    }

    // 方法二, 乘法bfs 超时
    int nthSuperUglyNumber1(int n, vector<int> &primes) {
        if (n == 1) {
            return 1;
        }
        queue<long long> q;
        q.push(1);
        vector<long long> vec;
        int ct = 1;
        vec.push_back(1);
        while (ct < n) {
            ++ct;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                long long val = q.front();
                q.pop();
                for (auto v  : primes) {
                    q.push(val * v);
                    vec.push_back(val * v);
                }
            }
            if (ct == n) {
                sort(vec.begin(), vec.end());
                unique(vec.begin(), vec.end());
                break;
            }
        }
        return vec[n - 1];
    }

    // 超时
    int nthSuperUglyNumber2(int n, vector<int> &primes) {
        if (n == 1) {
            return 1;
        }
        vector<pair<int, int>> vec;
        vec.push_back({1, 0});
        int ct = 1;
        while (ct < n) {
            ++ct;
            int small = INT_MAX;
            int p = -1;
            for (int i = 0; i < vec.size(); i++) {
                auto[v, t] = vec[i];
                if (t < primes.size()) {
                    int nv = v * primes[t];
                    if (nv <= vec.back().first) {
                        vec[i].second++;
                        --i;
                        continue;
                    }
                    if (nv < small) {
                        small = nv;
                        p = i;
                    }
                }
            }
            vec.push_back({small, 0});
            vec[p].second++;
        }
        return vec.back().first;
    }

       /*
     *  1 <= n <= 10e6
        1 <= primes.length <= 100
        2 <= primes[i] <= 1000
          题目数据 保证 primes[i] 是一个质数
          primes 中的所有值都 互不相同 ，且按 递增顺序 排列
     * */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n);
        dp[0] = 1;

        vector<int> times(primes.size());
        int ct = 1;
        while (ct < n) {
            int small = INT_MAX;
            for (int i = 0; i < primes.size(); i++) {
                if (primes[i] * dp[times[i]] < small) {
                    small = primes[i] * dp[times[i]];
                }
            }
            for (int i = 0; i < primes.size(); i++) {
                if (primes[i] * dp[times[i]] == small) {
                    ++times[i];
                }
            }
            dp[ct] = small;
            if (++ct == n) {
                break;
            }
        }
        return dp.back();
    }
};
// @lc code=end

