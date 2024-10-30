// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3244 lang=cpp
 * @lcpr version=30204
 *
 * [3244] 新增道路查询后的最短距离 II
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
#include <map>
#include <set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
namespace my_uf {

    template<typename T>
    class UF {
    public:
        vector<T> fa;
        int groupCnt;

        UF(int n) : fa(n) {
            iota(fa.begin(), fa.end(), 0);
            groupCnt = n;
        }

        T find(T u) {
            if (fa[u] == u) {
                return u;
            }
            return fa[u] = find(fa[u]);
        }

        // 左边合并到右边
        void merge(T u, T v) {
            T pu = find(u), pv = find(v);
            if (pu == pv) return;
            --groupCnt;
            if (pu > pv) {
                fa[pv] = pu;
            } else {
                fa[pu] = pv;
            }
        }

        bool same(int u, int v) {
            return find(u) == find(v);
        }

        int cnt() {
            return groupCnt;
        }
    };

    template<typename T>
    class UFR {
    public:
        vector<T> fa, rank;
        int groupCnt;

        UFR(int n) : fa(n), rank(n) {
            iota(fa.begin(), fa.end(), 0);
            fill(rank.begin(), rank.end(), 1);
            groupCnt = n;
        }

        T find(T u) {
            if (fa[u] == u) {
                return u;
            }
            return fa[u] = find(fa[u]);
        }

        void merge(T u, T v) {
            T pu = find(u), pv = find(v);
            if (pu == pv) return;
            --groupCnt;
            if (rank[pu] >= rank[pv]) {
                fa[pv] = pu;
                rank[pu] += rank[pv];
            } else {
                fa[pu] = pv;
                rank[pv] += rank[pu];
            }
        }

        bool same(int u, int v) {
            return find(u) == find(v);
        }

        int cnt() {
            return groupCnt;
        }
    };

};
using namespace my_uf;


class Solution {
public:
    // 超时
    vector<int> shortestDistanceAfterQueries1(int n, vector<vector<int>>& queries) {
        vector<int> g(n);
        for (int i = 0; i + 1 < n; i++) {
            g[i] = i + 1;
        }
        int m = queries.size();
        vector<int> ans(m);
        auto dfs = [&](auto&& dfs, int i) {
            if (i == n - 1) return 0;
            return dfs(dfs, g[i]) + 1;
        };
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            g[l] = max(g[l], r);
            ans[i] = dfs(dfs, 0);
        }
        return ans;
    }

    // 贪心, 删除多余区间
    vector<int> shortestDistanceAfterQueries2(int n, vector<vector<int>>& queries) {
        map<int, int> g;
        for (int i = 0; i + 1 < n; i++) {
            g[i] = i + 1;
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            // 删除 [l, r 之间的]
            auto beg = g.lower_bound(l);
            if (beg != g.end() and beg->first == l and beg->second < r) {
                while (beg != g.end() and beg->first < r) beg = g.erase(beg);
                g[l] = r;
            }
            ans[i] = g.size();
        }
        return ans;
    }

    vector<int> shortestDistanceAfterQueries3(int n, vector<vector<int>>& queries) {
        UF<int> uf(n);
        // for (int i = 0 ; i + 1 < n; i++) {
        //     uf.fa[i] = i + 1;
        // }
        int m = queries.size();
        vector<int> ans(m);
        int cnt = n - 1;
        for (int qi = 0; qi < m; qi++) {
            int l = queries[qi][0], r = queries[qi][1] - 1;
            int fr = uf.find(r);
            for (int j = uf.find(l); j < r; j = uf.find(j + 1)) {
                uf.fa[j] = fr;
                cnt--;
            }
            ans[qi] = cnt;
        }
        return ans;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> tr(n << 2), lazy(n << 2);
        auto _do = [&](int o, int l, int r, int v) {
            if (v == 1) {
                tr[o] = (r - l + 1) * v;
                lazy[o] = 1;
            } else {
                tr[o] = 0;
                lazy[o] = -1;
            }
        };

        auto update = [&](auto&& self, int o, int l, int r, int L, int R, int v) {
            if (L <= l and r <= R) {
                // 置为1或者0
                _do(o, l, r, v);
                return;
            }
            int m = (l + r) / 2;
            if (lazy[o]) {
                _do(o << 1, l, m, lazy[o]);
                _do(o << 1 | 1, m + 1, r, lazy[o]);
                lazy[o] = 0;
            }
            if (L <= m) self(self, o << 1, l, m, L, R, v);
            if (m < R) self(self, o << 1 |1, m + 1, r, L, R, v);
            tr[o] = tr[o << 1] + tr[o << 1 |1];
        };

        auto query = [&](auto&& self, int o, int l, int r, int L, int R) {
            if (L <= l and r <= R) {
                return tr[o];
            }
            int ans = 0;
            int m = (l + r) / 2;
            if (lazy[o]) {
                _do(o << 1, l, m, lazy[o]);
                _do(o << 1 | 1, m + 1, r, lazy[o]);
                lazy[o] = 0;
            }
            if (L <= m) ans += self(self, o << 1, l, m, L, R);
            if (m < R) ans += self(self, o << 1 |1, m + 1, r, L, R);
            tr[o] = tr[o << 1] + tr[o << 1 |1];
            return ans;
        };
        update(update, 1, 1, n - 1, 1, n - 1, 1);
        int m = queries.size();
        vector<int> ans(m);
        int cnt = n - 1;
        for (int qi = 0; qi < m; qi++) {
            int l = queries[qi][0] + 1, r = queries[qi][1] - 1;
            if (l <= r) {
                // 变成0
                update(update, 1, 1, n - 1, l, r, -1);
            }
            ans[qi] = query(query, 1, 1, n - 1, 1, n - 1);
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=shortestDistanceAfterQueries
// paramTypes= ["number","number[][]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 5\n[[2, 4], [0, 2], [0, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[0, 3], [0, 2]]\n
// @lcpr case=end

 */

