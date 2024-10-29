// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=685 lang=cpp
 * @lcpr version=30204
 *
 * [685] 冗余连接 II
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
            if (pu == fa.size() - 1) {
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& vec: edges) {
            int ma = max(vec[0], vec[1]);
            n = max(n, ma);
        }
        vector<int> indegree(n + 1);
        vector<int> outdegree(n + 1);
        int cnt1 = 0;
        auto add = [&](int p) {
            if (++indegree[p] > 1) {
                cnt1++;
            }
        };
        auto sub = [&](int p) {
            if (--indegree[p] == 1) {
                cnt1--;
            }
        };
        for (int i = 0; i < edges.size(); i++) {
            add(edges[i][1]);
        }
        for (int i = edges.size() - 1; i >= 0; i--) {
            sub(edges[i][1]);
            UF<int> uf(n + 1);
            bool flag = true;
            for (int j = 0; j < edges.size(); j++) {
                if (i == j) continue;
                int u = edges[j][0], v = edges[j][1];
               
                if (uf.same(u, v)) {
                    flag = false;
                    break;
                }
                uf.merge(u, v);
            }
            if (flag and cnt1 == 0) {
                return edges[i];
            }
            add(edges[i][1]);
        }
        return {0, 0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[2,3],[3,4],[4,1],[1,5]]\n
// @lcpr case=end

 */

