/*
 * @lc app=leetcode.cn id=1397 lang=cpp
 * @lcpr version=30204
 *
 * [1397] 找到所有好字符串
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
long long dp[2][2][510];

long long f[2][2][510][60];
const int mod = 1e9 + 7;
int       nxt[1000];
class Solution {
  public:
    int cal(string& s1, string& s2) {
        memset(dp, -1, sizeof(dp));
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int pos) -> int {
            if (pos >= s1.size()) {
                return 1;
            }
            auto&& ans = dp[isLow][isHigh][pos];
            if (ans != -1) {
                return ans;
            }
            ans      = 0;
            int low  = isLow ? s1[pos] : 'a';
            int high = isHigh ? s2[pos] : 'z';
            for (auto x = low; x <= high; x++) {
                ans = (ans + dfs(dfs, isLow and x == s1[pos], isHigh and x == s2[pos], pos + 1)) % mod;
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0);
    }

    // 错误的解法
    int cal2(string& s1, string& s2, string& evill) {
        long long ans = 0;
        // 枚举位置是错的, 并不能保证别的位置没有
        for (int i = 0; i + evill.size() <= s1.size(); i++) {
            memset(f, -1, sizeof(f));
            int  start = i;
            auto dfs   = [&](auto&& dfs, int isLow, int isHigh, int pos, int k) -> int {
                if (pos >= s1.size()) {
                    return 1;
                }
                auto&& ans = f[isLow][isHigh][pos][k];
                if (ans != -1) {
                    return ans;
                }
                ans      = 0;
                int low  = isLow ? s1[pos] : 'a';
                int high = isHigh ? s2[pos] : 'z';
                // 天选区间
                if (pos >= start and pos < start + evill.size()) {
                    // 找不到
                    if (evill[k] < low or evill[k] > high) {
                        return ans;
                    }
                    ans = dfs(dfs, isLow and evill[k] == s1[pos], isHigh and evill[k] == s2[pos], pos + 1, k + 1);
                } else {
                    for (auto x = low; x <= high; x++) {
                        ans = (ans + dfs(dfs, isLow and x == s1[pos], isHigh and x == s2[pos], pos + 1, k)) % mod;
                    }
                }
                return ans;
            };
            ans = (ans + dfs(dfs, 1, 1, 0, 0)) % mod;
        }
        return ans;
    }

    void makeNext(string& evill) {
        int k = 0;
        memset(nxt, 0, sizeof nxt);
        for (int i = 1; i < evill.size(); i++) {
            while (k and evill[k] != evill[i]) {
                k = nxt[k - 1];
            }
            if (evill[k] == evill[i])
                k++;
            nxt[i] = k;
        }
    }

    int cal3(string& s1, string& s2, string& evill) {
        memset(f, -1, sizeof(f));
        // k当前正在匹配evill的第k个字符
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int pos, int k) -> int {
            if (pos >= s1.size()) {
                return k == evill.size();
            }
            auto& ans = f[isLow][isHigh][pos][k];
            if (ans != -1) {
                return ans;
            }
            ans      = 0;
            int low  = isLow ? s1[pos] : 'a';
            int high = isHigh ? s2[pos] : 'z';
            for (auto x = low; x <= high; x++) {
                int nk = k;
                if (k < evill.size()) {
                    while (nk && evill[nk] != x) {
                        nk = nxt[nk - 1];
                    }
                    if (evill[nk] == x) {
                        nk++;
                    }
                }
                ans = (ans + dfs(dfs, isLow and x == s1[pos], isHigh and x == s2[pos], pos + 1, nk)) % mod;
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }

    int findGoodStrings1(int n, string s1, string s2, string evil) {
        makeNext(evil);
        // s1 s2 字符串总数 - 包含evil 字符串的数量
        int x1 = cal(s1, s2);
        int x2 = cal3(s1, s2, evil);
        return (x1 - x2 + mod) % mod;
    }

    int cal4(string& s1, string& s2, string& evill) {
        memset(f, -1, sizeof(f));
        // k当前正在匹配evill的第k个字符
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int pos, int k) -> int {
            if (pos >= s1.size()) {
                return 1;
            }
            auto& ans = f[isLow][isHigh][pos][k];
            if (ans != -1) {
                return ans;
            }
            ans      = 0;
            int low  = isLow ? s1[pos] : 'a';
            int high = isHigh ? s2[pos] : 'z';
            for (auto x = low; x <= high; x++) {
                int nk = k;
                while (nk && evill[nk] != x) {
                    nk = nxt[nk - 1];
                }
                if (evill[nk] == x) {
                    nk++;
                }
                if (nk == evill.size()) {
                    continue;
                }
                ans = (ans + dfs(dfs, isLow and x == s1[pos], isHigh and x == s2[pos], pos + 1, nk)) % mod;
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0);
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        makeNext(evil);
        // s1 s2 字符串总数 - 包含evil 字符串的数量
        return cal4(s1, s2, evil);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n"aa"\n"da"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// 8\n"leetcode"\n"leetgoes"\n"leet"\n
// @lcpr case=end

// @lcpr case=start
// 2\n"gx"\n"gz"\n"x"\n
// @lcpr case=end

 */
