/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
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
    constexpr static int Mod = 1e9 + 7;

    // bfs 超时
    void knightDialerHelper(unordered_map<int, vector<int>>& next_pos, unordered_set<string>& times, int n, int number) {
        string cur(1, number + '0');
        queue<pair<string, int>> q;
        q.push({cur, number});
        for (int i = 2; i <= n; i++) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                auto [str, pos] = q.front(); q.pop();
                for (auto next : next_pos[pos]) {
                    string temp = str;
                    temp.push_back(next);
                    q.push(make_pair(temp, next));
                    if (i == n) {
                        times.insert(temp);
                    }
                }
            }
        }
        return;
    }

    int knightDialer1(int n) {
        // cur_n, times
        unordered_set<string>  times;
        unordered_map<int, vector<int>> next_pos;
        next_pos[0] = {4, 6};
        next_pos[1] = {6, 8};
        next_pos[2] = {7, 9};
        next_pos[3] = {4, 8};
        next_pos[4] = {0, 3, 9};
        next_pos[6] = {0, 1, 7};
        next_pos[7] = {2, 6};
        next_pos[8] = {1, 3};
        next_pos[9] = {2, 4};
        for (int i = 0; i <= 9; i++) {
            if (n == 1) {
                times.insert(to_string(i));
            } else {
                knightDialerHelper(next_pos, times, n, i);
            }
        }
        return times.size() % Mod;
    }

    int knightDialer(int n) {
        // cur_n, times
        unordered_map<int, vector<int>> next_pos;
        next_pos[0] = {4, 6};
        next_pos[1] = {6, 8};
        next_pos[2] = {7, 9};
        next_pos[3] = {4, 8};
        next_pos[4] = {0, 3, 9};
        next_pos[6] = {0, 1, 7};
        next_pos[7] = {2, 6};
        next_pos[8] = {1, 3};
        next_pos[9] = {2, 4};

#define ROLL
#ifndef ROLL
        vector<vector<long>> dp(10, vector<long>(n, 0));
        for (int i = 0; i < 10; i++) {
            dp[i][0] = 1;
        }
        long long ans = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 10; i++) {
                for (auto next : next_pos[i]) {
                    dp[i][j] += dp[next][j - 1];
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            ans += dp[i][n - 1];
        }
        return ans % Mod;
#else
        vector<vector<long>> dp(10, vector<long>(2, 0));
        for (int i = 0; i < 10; i++) {
            dp[i][0] = 1;
        }
        long long ans = 0;
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < 10; i++) {
                dp[i][j & 0x1] = 0;
                for (auto next : next_pos[i]) {
                    dp[i][j & 0x1] =  (dp[i][j & 0x1] + dp[next][(j - 1) & 0x1]) % Mod;
                }
            }
        }
        for (int i = 0; i < 10; i++) {
            ans += dp[i][(n - 1) & 0x1];
        }
        return ans % Mod;
#endif
    }
};
// @lc code=end

