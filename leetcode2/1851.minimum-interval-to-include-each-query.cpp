// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1851 lang=cpp
 * @lcpr version=30204
 *
 * [1851] 包含每个查询的最小区间
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
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        ranges::sort(intervals, [&](auto& a, auto& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        vector<pair<int, int>> q(n);
        for (int i = 0 ; i < n; i++) {
            q[i] = {queries[i], i};
        }
        ranges::sort(q);
        vector<int> ans(n, -1);
        UF<int> uf(n + 1);
        for (auto& seg: intervals) {
            int l = seg[0], r = seg[1], d = seg[1] - seg[0] + 1;
            // 找到第一 >= l 的区间
            auto i = lower_bound(q.begin(), q.end(), l, [&](auto it, int v) {
                return it.first < v;
            }) - q.begin();
            if (i == n) {
                continue;
            }
            for (i = uf.find(i); i < n and q[i].first<= r; i = uf.find(i + 1)) {
                ans[q[i].second] = d;
                uf.fa[i] = i + 1;
            }
        }
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=minInterval
// paramTypes= ["number[][]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [[1,4],[2,4],[3,6],[4,4]]\n[2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[2,5],[1,8],[20,25]]\n[2,19,5,22]\n
// @lcpr case=end

 */

