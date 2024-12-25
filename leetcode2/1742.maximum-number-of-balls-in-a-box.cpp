/*
 * @lc app=leetcode.cn id=1742 lang=cpp
 * @lcpr version=30204
 *
 * [1742] 盒子中小球的最大数量
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
#include <string.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
  public:
    // 暴力
    int countBalls_brute(int lowLimit, int highLimit) {
        unordered_map<int, int> cnt;
        for (int i = lowLimit; i <= highLimit; i++) {
            string s = to_string(i);
            cnt[reduce(s.begin(), s.end(), 0, [](int init, char ch) { return init + (ch - '0'); })]++;
        }
        int ma = 0;
        for (auto& [k, v] : cnt) {
            ma = max(ma, v);
        }
        return ma;
    }

    int countBalls2(int lowLimit, int highLimit) {
        // 数位dp
        string s = to_string(lowLimit), t = to_string(highLimit);
        if (s.size() < t.size()) {
            s = string(t.size() - s.size(), '0') + s;
        }
        vector<int> f(50, -1);
        auto cal = [&](int sum) {
            int         dp[2][2][100][20];
            memset(dp, -1, sizeof dp);
            auto dfs = [&](auto&& dfs, int isLow, int isHigh, int left, int pos)->int {
                if (pos >= s.size()) {
                    return left == 0;
                }
                auto& ans = dp[isLow][isHigh][left][pos];
                if (ans != -1) {
                    return ans;
                }
                ans       = 0;
                int low  = isLow ? s[pos] : '0';
                int high = isHigh ? t[pos] : '9';
                for (int x = low; x <= min(high, left + '0'); x++) {
                    ans += dfs(dfs, isLow and x == s[pos], isHigh and x == t[pos], left - (x - '0'), pos + 1);
                }
                return ans;
            };
            if (f[sum] == -1) {
                f[sum] = dfs(dfs, 1, 1, sum, 0);
            }
            return f[sum];
        };
        int ans = 0;
        for (int i = 1; i < f.size(); i++) {
            ans = max(ans, cal(i));
        }
        return ans;
    }

    // 数学
    int countBalls(int lowLimit, int highLimit) {
        vector<int> f(50, 0);
        int index = 0;
        for (int v = lowLimit; v; v /= 10) {
            index += v % 10;
        }
        f[index]++;
        for (int i = lowLimit; i < highLimit; i++) {
            for (int v = i; v % 10 == 9; v /= 10) {
                index -= 9;
            }
            f[++index]++;
        }
        int ans = 0;
        for (int i = 1; i < f.size(); i++) {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n10\n
// @lcpr case=end

// @lcpr case=start
// 5\n15\n
// @lcpr case=end

// @lcpr case=start
// 19\n28\n
// @lcpr case=end

 */
