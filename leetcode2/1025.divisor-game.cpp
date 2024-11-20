/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 * @lcpr version=30204
 *
 * [1025] 除数博弈
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
    vector<int> calG(int n) {
        vector<int> g(n + 1), s(n + 2);
        auto getdiv = [&](int v) {
            vector<int> res{1};
            for (int i = 2; i * i <= v; i++) {
                if (v % i == 0) {
                    res.push_back(i);
                    if (i * i != v) res.push_back(v / i);
                }
            }
            ranges::sort(res);
            return res;
        };
        for (int i = 2; i <= n; i++) {
            fill(s.begin(), s.end(), 0);
            auto candidate = getdiv(i);
            for (int j = 0; j < candidate.size() and candidate[j] <= i; j++) {
                s[g[i - candidate[j]]] = 1;
            }
            int res = 0;
            while (s[res]) res++;
            g[i] = res;
        }
        return g;
    }

    bool divisorGame_g(int n) {
        return calG(n)[n];
    }

    bool divisorGame2(int n) {
        vector<int> dp(n + 1, INT_MAX);
        auto getdiv = [&](int v) {
            vector<int> res{1};
            for (int i = 2; i * i <= v; i++) {
                if (v % i == 0) {
                    res.push_back(i);
                    if (i * i != v) res.push_back(v / i);
                }
            }
            ranges::sort(res);
            return res;
        };
        auto dfs = [&](auto&& dfs, int v)->bool {
            if (v <= 1) {
                return false;
            }
            if (dp[v] != INT_MAX) return dp[v];
            auto candidate = getdiv(v);
            bool ok = false;
            for (int j = 0; j < candidate.size() and candidate[j] <= v; j++) {
                ok |= !dfs(dfs, v - candidate[j]);
            }
            return dp[v] = ok;
        };
        return dfs(dfs, n);
    }

    
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

