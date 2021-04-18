/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
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

    /*
        宽度优先
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
        queue<int> q;
        q.push(n);
        int times = 0;
        while(!q.empty()) {
            ++times;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int node = q.front();
                q.pop();
                auto ite = lower_bound(pri.begin(), pri.end(), node);
                int index = pri.size() - 1;
                if (ite != pri.end()) {
                    index = ite - pri.begin();
                }
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
};
// @lc code=end

int main() { cout << Solution{}.numSquares(12); }
