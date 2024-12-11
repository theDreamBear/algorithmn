/*
 * @lc app=leetcode.cn id=2800 lang=cpp
 * @lcpr version=30204
 *
 * [2800] 包含三个字符串的最短字符串
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
#include <random>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
mt19937 rng(233);
int     rnd(int x, int y) {
    return uniform_int_distribution<int>(x, y)(rng);
}

long long MOD = 1e18 + rnd(0, 1e9), BASE = 233 + rnd(0, 1e3);
struct HashObj {
    vector<__int128> P, H;

    template <typename Container> HashObj(Container& s) {
        int n = s.size();
        P.resize(n + 1);
        P[0] = 1;
        for (int i = 1; i <= n; i++)
            P[i] = P[i - 1] * BASE % MOD;
        H.resize(n + 1);
        H[0] = 0;
        for (int i = 1; i <= n; i++)
            H[i] = (H[i - 1] * BASE + s[i - 1]) % MOD;
    }
    // [l, r]
    long long query(int l, int r) {
        if (l > r)
            return 0;
        return (H[r + 1] - H[l] * P[r - l + 1] % MOD + MOD) % MOD;
    }
};

class Solution {
  public:
    string minimumString1(string a, string b, string c) {
        // 直接生成就行了
        auto gen = [&](string& s, string& t, string& v) {
            string ans = s;
            auto   cat = [&](string& other) {
                // ans 的后缀和 other 前缀的最大值
                // 暴力
                bool ok = false;
                int  m = ans.size(), n = other.size();
                int  i = min(m, n);
                while (i and !ok) {
                    ok = true;
                    for (int j = m - i; j < m; j++) {
                        if (ans[j] != other[j - m + i]) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                    i--;
                }
                ans += other.substr(i);
            };
            if (ans.find(t) == string::npos) {
                cat(t);
            }
            if (ans.find(v) == string::npos) {
                cat(v);
            }
            return ans;
        };
        vector<string> words{a, b, c};
        vector<int>    perm{0, 1, 2};
        string         ans;
        int            len = INT_MAX;
        do {
            auto res = gen(words[perm[0]], words[perm[1]], words[perm[2]]);
            if (res.size() < len or (res.size() == len and res < ans)) {
                ans = res;
                len = ans.size();
            }
        } while (next_permutation(perm.begin(), perm.end()));
        return ans;
    }

    string minimumString(string a, string b, string c) {
        // 直接生成就行了
        auto gen = [&](string& s, string& t, string& v) {
            string ans = s;
            // 怎么更快找到, 一个字符串的后缀和另一个的前缀的最长公共串
            auto maxLen = [&](string& lhs, string& rhs) {
                // z 函数
                string      s = rhs + "#" + lhs;
                int         n = s.size();
                vector<int> z(n);
                int         l = 0, r = 0;
                z[0] = n;
                for (int i = 1; i < n; i++) {
                    if (i <= r)
                        z[i] = min(r - i + 1, z[i - l]);
                    while (i + z[i] < n and s[z[i]] == s[i + z[i]])
                        z[i]++;
                    if (i + z[i] > r) {
                        l = i;
                        r = i + z[i] - 1;
                    }
                }
                int j  = rhs.size() + 1;
                int ma = 0;
                for (; j < n; j++) {
                    if (j + z[j] == n) {
                        ma = max(ma, z[j]);
                    }
                }
                return ma;
            };
            if (ans.find(t) == string::npos) {
                ans += t.substr(maxLen(ans, t));
            }
            if (ans.find(v) == string::npos) {
                ans += v.substr(maxLen(ans, v));
            }
            return ans;
        };
        vector<string> words{a, b, c};
        vector<int>    perm{0, 1, 2};
        string         ans;
        int            len = INT_MAX;
        do {
            auto res = gen(words[perm[0]], words[perm[1]], words[perm[2]]);
            if (res.size() < len or (res.size() == len and res < ans)) {
                ans = res;
                len = ans.size();
            }
        } while (next_permutation(perm.begin(), perm.end()));
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n"aaa"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n"ba"\n"aba"\n
// @lcpr case=end

 */
