/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
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
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


    int quickExp(int value, int k) {
        int ans = 1;
        while (k) {
            if (k % 2 != 0) {
                ans *= value;
            }
            value *= value;
            k >>= 1;
        }
        return ans;
    }

    int knightProbabilityHelper(int n, int k, int row, int column) {
        if (k <= 0) {
            return 1;
        }
        int sum = 0;
        for (int i = 0; i < 8; i++) {
            int x = row + dx[i];
            int y = column + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n) {
                continue;
            }
            sum += knightProbabilityHelper(n, k - 1, x, y);
        }
        return sum;
    }

    /*
     * 超时
     * */
    double knightProbability1(int n, int k, int row, int column) {
        return knightProbabilityHelper(n, k, row, column) * 1.0 / quickExp(8, k);
    }

    /* 问题, 多次计算同一个位置
     *
     * */
    double knightProbability2(int n, int k, int row, int column) {
        if (k == 0) {
            return 1;
        }
        queue<int> q;
        q.push(row * 25 + column);
        unordered_map<int, double> hash;
        vector<int> dp(n * 25 + n);
        double ans = 1;
        while (k && !q.empty()) {
            --k;
            int t = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int v = q.front();
                q.pop();
                int x = v / 25;
                int y = v % 25;
                for (int j = 0; j < 8; ++j) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                        continue;
                    }
                    int temp = nx * 25 + ny;
                    t++;
                    q.push(temp);
                }
            }
            ans *= (t * 1.0 / (sz * 8));
        }
        return ans;
    }

    double knightProbabilityHelper2(int n, int k, int x, int y, vector<vector<double>>& dp) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            return 0;
        }
        if (k <= 0) {
            return 1;
        }
        int value = x * 25 + y;
        if (dp[k][value]) {
            return dp[k][value];
        }
       // int t = 0;
        double sum = 0;
        for (int j = 0; j < 8; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
                continue;
            }
            //++t;
            int temp = nx * 25 + ny;
            if (dp[k - 1][temp]) {
                sum += dp[k - 1][temp];
                continue;
            }
            sum += knightProbabilityHelper2(n, k - 1, nx, ny, dp);
        }
        return dp[k][value] = sum / 8;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(k + 1, vector<double>(625, 0));
        return knightProbabilityHelper2(n, k, row, column, dp);
    }
};

// @lc code=end

