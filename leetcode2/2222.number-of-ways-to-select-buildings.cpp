// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2222 lang=cpp
 * @lcpr version=30204
 *
 * [2222] 选择建筑的方案数
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
    long long numberOfWays1(string s) {
        auto handler = [&](int i, int j, int last) -> pair<bool, long long> {
            if (j == 0) {
                return {true, 1};
            }
            if (i < 0 || j < 0 || last < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = s.size();
        long long dp[n][4][2];
        auto get_v = [&](int i, int j, int k) {
            if (auto res = handler(i, j, k); res.first) {
                return res.second;
            }
            return dp[i][j][k];
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == '0') {
                    dp[i][j][0] = get_v(i - 1, j, 0) + get_v(i - 1, j - 1, 1);
                    dp[i][j][1] = get_v(i - 1, j, 1);
                } else {
                    dp[i][j][0] = get_v(i - 1, j, 0);
                    dp[i][j][1] = get_v(i - 1, j, 1) + get_v(i - 1, j - 1, 0);
                }
            }
        }
        return dp[n - 1][3][0] + dp[n - 1][3][1];
    }

    long long numberOfWays2(string s) {
        auto handler = [&](int i, int j, int last) -> pair<bool, long long> {
            if (j == 0) {
                return {true, 1};
            }
            if (i < 0 || j < 0 || last < 0) {
                return {true, 0};
            }
            return {false, 0};
        };
        int n = s.size();
        long long dp[2][4][2];
        int ft = 0, st = 1;
        auto get_v = [&](int i, int j, int k) {
            if (auto res = handler(i, j, k); res.first) {
                return res.second;
            }
            return dp[ft][j][k];
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == '0') {
                    dp[st][j][0] = get_v(i - 1, j, 0) + get_v(i - 1, j - 1, 1);
                    dp[st][j][1] = get_v(i - 1, j, 1);
                } else {
                    dp[st][j][0] = get_v(i - 1, j, 0);
                    dp[st][j][1] = get_v(i - 1, j, 1) + get_v(i - 1, j - 1, 0);
                }
            }
            swap(ft, st);
        }
        return dp[ft][3][0] + dp[ft][3][1];
    }

    long long numberOfWays3(string s) {
        // 010, 101
        vector<int> cnt[2];
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - '0'].push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int idx = !(s[i] - '0');
            auto lv = lower_bound(cnt[idx].begin(), cnt[idx].end(), i) -  cnt[idx].begin();
            auto rv = cnt[idx].end() - upper_bound(cnt[idx].begin(), cnt[idx].end(), i);
            ans += (lv * rv);
        }
        return ans;
    }

    long long numberOfWays(string s) {
        // 010, 101
        long long lnt[2]{}, rnt[2]{};
        for (int i = 0; i < s.size(); i++) {
            rnt[s[i] - '0']++;
        }
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            rnt[s[i] - '0']--;
            lnt[s[i] - '0']++;

            int idx = !(s[i] - '0');
            ans += lnt[idx] * rnt[idx];

        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName="001101"
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// "001101"\n
// @lcpr case=end

// @lcpr case=start
// "11100"\n
// @lcpr case=end

 */
