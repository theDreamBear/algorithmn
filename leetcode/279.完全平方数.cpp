/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
    /*
        超时
    */
    int numSquares1(int n) {
        if (n <= 3) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            int s = sqrt(i);
            if (s * s == i) {
                dp[i] = 1;
            } else {
                int times = i;
                // 下面的逻辑可以优化
                for (int j = 1; j <= i / 2; ++j) {
                    if (dp[j] + dp[i - j] < times) {
                        times = dp[j] + dp[i - j];
                    }
                }
                dp[i] = times;
            }
        }
        return dp[n];
    }

    int numSquares1_plus(int n) {
        if (n <= 3) {
            return n;
        }
        int sqr = sqrt(n);
        if (sqr * sqr == n) {
            return 1;
        }
        vector<int> pri;
        for (int i = 1; i <= sqr; ++i) {
            pri.push_back(i * i);
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            int s = sqrt(i);
            if (s * s == i) {
                dp[i] = 1;
            } else {
                int times = i;
                // 下面的逻辑可以优化
                int j =
                    lower_bound(pri.begin(), pri.end(), s * s) - pri.begin();
                for (; j > 0; --j) {
                    int t = dp[pri[j]] + dp[i - pri[j]];
                    if (t < times) {
                        times = t;
                    }
                    // 最小值为 2, 提前结束
                    if (t == 2) {
                        break;
                    }
                }
                dp[i] = times;
            }
        }
        return dp[n];
    }

    /*
        宽度优先, 深度优先遍历复杂度更高
        使用双宽度优先遍历加速
    */
    int numSquares2(int n) {
        if (n <= 3) {
            return n;
        }
        int sqr = sqrt(n);
        if (sqr * sqr == n) {
            return 1;
        }
        vector<int> pri;
        for (int i = 1; i <= sqr; ++i) {
            pri.push_back(i * i);
        }
        queue<int> q;
        q.push(n);
        int times = 0;
        while (!q.empty()) {
            ++times;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int node = q.front();
                q.pop();
                auto ite = lower_bound(pri.begin(), pri.end(), node);
                int index = min(int(pri.size() - 1), int(ite - pri.begin()));
                for (int j = index; j >= 0; --j) {
                    if (node < pri[j]) {
                        continue;
                    }
                    if (node == pri[j]) {
                        return times;
                    }
                    if (node > pri[j]) {
                        q.push(node - pri[j]);
                    }
                }
            }
        }
        return 0;
    }

    /*
        宽度优先遍历加速, 双宽度优先算法
    */
    int numSquares(int n) {
        if (n <= 3) {
            return n;
        }
        int sqr = sqrt(n);
        if (sqr * sqr == n) {
            return 1;
        }
        vector<int> pri;
        for (int i = 1; i <= sqr; ++i) {
            pri.push_back(i * i);
        }
        queue<int> lq;
        queue<int> rq;
        lq.push(n);
        rq.push(0);

        unordered_set<int> ltimes;
        unordered_set<int> rtimes;
        int left = 0;
        int right = 0;
        while (!lq.empty() && !rq.empty()) {
            // lq 搜索
            ++left;
            int sz = lq.size();
            for (int i = 0; i < sz; ++i) {
                int node = lq.front();
                lq.pop();
                auto ite = lower_bound(pri.begin(), pri.end(), node);
                int index = min(int(pri.size() - 1), int(ite - pri.begin()));
                for (; index >= 0; --index) {
                    if (node < pri[index]) {
                        continue;
                    }
                    if (node == pri[index]) {
                        return left;
                    }
                    int lleft = node - pri[index];
                    if (rtimes.count(lleft) > 0) {
                        return left + right;
                    }
                    ltimes.insert(lleft);
                    lq.push(lleft);
                }
            }
            ++right;
            sz = rq.size();
            for (int i = 0; i < sz; ++i) {
                int node = rq.front();
                rq.pop();
                auto ite = lower_bound(pri.begin(), pri.end(), n - node);
                int index = min(int(pri.size() - 1), int(ite - pri.begin()));
                for (; index >= 0; --index) {
                    if (n - node < pri[index]) {
                        continue;
                    }
                    if (n - node == pri[index]) {
                        return right;
                    }
                    int rleft = node + pri[index];
                    if (ltimes.count(rleft) > 0) {
                        return left + right;
                    }
                    rtimes.insert(rleft);
                    rq.push(rleft);
                }
            }
        }
        return 0;
    }
};
// @lc code=end

int main() { cout << Solution{}.numSquares(12); }
