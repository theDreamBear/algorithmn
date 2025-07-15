/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 * @lcpr version=30204
 *
 * [1319] 连通网络的操作次数
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
   class UF {
public:
    vector<int> pa;

    UF(int n): pa(n){
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int u) {
        if (pa[u] == u) return u;
        return pa[u] = find(pa[u]);
    }

    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        pa[pu] = pv;
    }

    bool isConnect(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    int makeConnected_status(int n, vector<vector<int>>& connections) {
        // 计算所有的联通块, 并统计多以的线缆个数
        int cnt = 0, left = 0;
        vector<int> marked(n);
        vector<vector<int>> adj(n);
        for (auto& c: connections) {
            int a = c[0], b = c[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto dfs = [&] (auto&& dfs, int u, int fa)->void {
            // 1 是访问中
            marked[u] = 1;
            for (auto v: adj[u]) {
                if (marked[v]) {
                    // 访问中的点, 在当前调用链路中的, 构成环了
                    if (marked[v] == 1 and v != fa) {
                        left++;
                    }
                    continue;
                }
                dfs(dfs, v, u);
            }
            // 2 是访问结束
            marked[u] = 2;
        };
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                ++cnt;
                dfs(dfs, i, -1);
            }
        }
        if (left + 1 >= cnt) {
            return cnt - 1;
        }
        return -1;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // 计算所有的联通块, 并统计多以的线缆个数
        int cnt = 0;
        // 并查集
        UF uf(n);
        //int cnt = 0;
        for (auto& conn: connections) {
            int a = conn[0], b = conn[1];
            if (uf.isConnect(a, b)) {
                cnt++;
            } else {
                uf.merge(a, b);
            }
        }
        unordered_set<int> roots;
        for (int i = 0; i < n; i++) {
            roots.insert(uf.find(i));
        }
        if (cnt >= roots.size() - 1) {
            return roots.size() - 1;
        }
        return -1;
    }

    int makeConnected_dfs(int n, vector<vector<int>>& connections) {
        // 计算所有的联通块, 并统计多以的线缆个数
        int cnt = 0;
        vector<int> marked(n);
        vector<vector<int>> adj(n);
        for (auto& c: connections) {
            int a = c[0], b = c[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int m = connections.size();
        auto dfs = [&] (auto&& dfs, int u)->int {
            marked[u] = 1;
            int sz = 1;
            for (auto v: adj[u]) {
                if (marked[v]) {
                    continue;
                }
                sz += dfs(dfs, v);
            }
            return sz;
        };
        for (int i = 0; i < n; i++) {
            if (!marked[i]) {
                ++cnt;
                // 每个联通块使用的绳子数
                m -= (dfs(dfs, i)- 1);
            }
        }
        // 剩余绳子个数太少了
        if (m < cnt - 1) {
            return -1;
        }
        return cnt - 1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[[0,1],[0,2],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[0,3],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[0,1],[0,2],[0,3],[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1],[0,2],[3,4],[2,3]]\n
// @lcpr case=end

 */

