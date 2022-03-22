/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] 蛇梯棋
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
    int nextMost(int cur, int n) {
        return min(cur + 6, n * n);
    }

    pair<int, int> parsePos(int cur, int n) {
        int r = (cur - 1) / n;
        int c = (cur - 1) % n;
        if (r % 2 == 0) {
            return {n - r - 1, c};
        } else {
            return {n - r - 1, n - c - 1};
        }
    }

    int snakesAndLadders(vector<vector<int>> &board) {
        if (board.empty() || board.size() == 1) {
            return 0;
        }
        int n = board.size();
        int destination = n * n;
        vector<int> times(n * n + 1, INT_MAX);
        queue<int> q;
        q.push(1);
        int ct = 0;
        while (!q.empty()) {
            ++ct;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto v = q.front();
                q.pop();
                int most = nextMost(v, n);
                while (v < most) {
                    v++;
                    auto[r, c] = parsePos(v, n);
                    int next = v;
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }
                    if (next == destination) {
                        return ct;
                    }
                    if (times[next] == INT_MAX) {
                        times[next] = ct;
                        q.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

