/*
 * @lc app=leetcode.cn id=1654 lang=cpp
 *
 * [1654] 到家的最少跳跃次数
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
constexpr int base = 1 << 12;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x == 0) {
            return 0;
        }
        int times = 1e7 + 7;
        unordered_set<int> forbidden_pos(forbidden.begin(), forbidden.end());
        queue<int> q;
        q.push(0);
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                --times;
                if (times == 0) {
                    return -1;
                }
                auto v = q.front();
                q.pop();
                int t = v >> 12;
                int actual = v & (base - 1);
                if (actual == x) {
                    return ans - 1;
                }
                forbidden_pos.insert(actual);
                // 往前
                int after = actual + a;
                if (forbidden_pos.count(after) == 0) {
                    q.push(after);
                }
                // 往后
                if (t == 2) {
                    continue;
                }
                int b1 = actual - b;
                int v1 = (1 << 12) + b1;
                int v2 = (2 << 12) + b1;
                if (t < 2 && forbidden_pos.count(v1) == 0) {
                    q.push(v1);
                }
                if (t == 0 && forbidden_pos.count(v2) == 0) {
                    q.push(v2);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

