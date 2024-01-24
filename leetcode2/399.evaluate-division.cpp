/*
 * @lc app=leetcode.cn id=399 lang=cpp
 * @lcpr version=30113
 *
 * [399] 除法求值
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
#include <numeric>
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
    class Alloc {
      public:
        unordered_map<string, int> keyToIdx;
        int                        maxIdx = 0;

        int allocAndGet(const string& key) {
            alloc(key);
            return keyToIdx[key];
        }

        void alloc(const string& key) {
            if (!contains(key)) {
                keyToIdx[key] = maxIdx++;
            }
        }

        int getId(const string& key) {
            if (contains(key)) {
                return keyToIdx[key];
            }
            return -1;
        }

        bool contains(const string& key) const {
            return keyToIdx.count(key) > 0;
        };

        int MaxIdx() const {
            return maxIdx;
        }
    };

    // 丑陋的解法: bfs
    vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Alloc                  alloc;
        vector<vector<double>> grid(40, vector<double>(40, -1));
        // 填值
        for (int i = 0; i < equations.size(); i++) {
            int    lhs     = alloc.allocAndGet(equations[i][0]);
            int    rhs     = alloc.allocAndGet(equations[i][1]);
            double score   = values[i];
            grid[lhs][rhs] = score;
            grid[rhs][lhs] = 1.0 / score;
        }
        for (int i = 0; i < alloc.MaxIdx(); i++) {
            grid[i][i] = 1;
        }
        auto bfs = [&](int start, int target) {
            queue<pair<int, double>> q;
            vector<int>              visited(alloc.MaxIdx());

            visited[start] = 1;
            q.push({start, 1});

            while (!q.empty()) {
                int sz = q.size();
                while (sz-- > 0) {
                    auto [node, score] = q.front();
                    q.pop();
                    // 邻接点
                    for (int i = 0; i < alloc.MaxIdx(); i++) {
                        if (grid[node][i] != -1 && !visited[i]) {
                            double now     = score * grid[node][i];
                            grid[start][i] = now;
                            if (i == target) {
                                return;
                            }
                            visited[i] = 1;
                            q.push({i, now});
                        }
                    }
                }
            }
            return;
        };
        vector<double> ans((queries.size()), -1.0);
        for (int i = 0; i < queries.size(); i++) {
            if (!alloc.contains(queries[i][0]) || !alloc.contains(queries[i][1])) {
                continue;
            }
            int lhs = alloc.getId(queries[i][0]);
            int rhs = alloc.getId(queries[i][1]);
            if (grid[lhs][rhs] == -1) {
                bfs(lhs, rhs);
            }
            ans[i] = grid[lhs][rhs];
        }
        return ans;
    }

    class BackGurad {
     public:
        vector<int>& visited;
        int pos;
        BackGurad(vector<int>& visited, int i): visited(visited), pos(i) {
            visited[pos] = 1;
        }

        ~BackGurad() {
            visited[pos] = 0;
        }
    };

    // dfs + 回溯 性能比bfs好
    vector<double> calcEquation2(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Alloc                  alloc;
        vector<vector<double>> grid(40, vector<double>(40, -1));
        // 构建图
        for (int i = 0; i < equations.size(); i++) {
            int    lhs     = alloc.allocAndGet(equations[i][0]);
            int    rhs     = alloc.allocAndGet(equations[i][1]);
            double score   = values[i];
            grid[lhs][rhs] = score;
            grid[rhs][lhs] = 1.0 / score;
        }
        // 初始化
        for (int i = 0; i < alloc.MaxIdx(); i++) {
            grid[i][i] = 1;
        }
        // dfs
        vector<int>                   visited(40);
        function<bool(int, int, int)> dfs = [&](int source, int target, int cur) {
            for (int i = 0; i < alloc.MaxIdx(); i++) {
                // 没有访问过且互通
                if (!visited[i] && grid[cur][i] != -1) {
                    grid[source][i] = grid[source][cur] * grid[cur][i];
                    if (i == target) {
                        return true;
                    }
                    BackGurad gurad(visited, i);
                    bool ret   = dfs(source, target, i);
                    if (ret) {
                        return true;
                    }
                }
            }
            return false;
        };
        vector<double> ans;
        for (const auto& vec : queries) {
            int lhs = alloc.getId(vec[0]);
            int rhs = alloc.getId(vec[1]);
            int ret = -1;
            if (lhs != -1 && rhs != -1) {
                BackGurad gurad(visited, lhs);
                if (dfs(lhs, rhs, lhs)) {
                    ret = grid[lhs][rhs];
                }
            }
        }
        return ans;
    }

    class UnionFind {
      public:
        vector<int>    parent;
        vector<double> weight;

        UnionFind(int sz) : parent(sz), weight(sz) {
            iota(parent.begin(), parent.end(), 0);
            fill(weight.begin(), weight.end(), 1);
        }

        void merge(int w, int v, double score) {
            auto [pw, sw] = find(w);
            auto [pv, sv] = find(v);
            if (pw == pv) {
                return;
            }
            parent[pv] = pw;
            weight[pv] = sw / sv / score;
        }

        /**
         * @brief
         *
         * @param w 节点
         * @return pair<int, double>  返回root节点和score
         * @node 边找边压缩
         */
        pair<int, double> find(int w) {
            // 自己就是自己的的parent
            if (parent[w] == w) {
                return {w, 1};
            }
            // parent 的情况
            auto [p, s] = find(parent[w]);
            parent[w]   = p;
            weight[w] *= s;
            return {p, weight[w]};
        }

        bool isConnected(int w, int v) {
            return find(w).first == find(v).first;
        }

        double getWeight(int w) {
            return weight[w];
        }
    };

    // elegant
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        Alloc     alloc;
        UnionFind uf(40);
        for (int i = 0; i < equations.size(); i++) {
            const auto& vec = equations[i];
            int         lhs = alloc.allocAndGet(vec[0]);
            int         rhs = alloc.allocAndGet(vec[1]);
            uf.merge(lhs, rhs, values[i]);
        }
        vector<double> ans(queries.size(), -1);
        transform(queries.begin(), queries.end(), ans.begin(), [&](const vector<string>& query) {
            double res = -1;
            if (alloc.contains(query[0]) && alloc.contains(query[1])) {
                int lhs = alloc.getId(query[0]);
                int rhs = alloc.getId(query[1]);
                if (uf.isConnected(lhs, rhs)) {
                    res = uf.getWeight(lhs) / uf.getWeight(rhs);
                }
            }
            return res;
        });
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [["a","b"],["b","c"]]\n[2.0,3.0]\n[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// @lcpr case=end

// @lcpr case=start
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
// @lcpr case=end

 */
