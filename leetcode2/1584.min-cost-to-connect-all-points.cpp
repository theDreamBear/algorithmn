/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 * @lcpr version=30114
 *
 * [1584] 连接所有点的最小费用
 */


// @lcpr-template-start
#include <cstddef>
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
    class HashFn {
    public:
        size_t operator()(const pair<int, int>& p) const{
            return (hash<int>()(p.first) << 5) ^ (hash<int>()(p.second) >> 5);
        };

    };

    class Alloc {
    public:
        unordered_map<pair<int, int>, int, HashFn> h;
        vector<pair<int, int>> data;

        int alloc(int x, int y) {
            auto p = make_pair(x, y);
            if (h.count(p)) {
                return h[p];
            }
            data.push_back(p);
            return h[p] = data.size() - 1;
        }

        int size() const {
            return data.size();
        }

        pair<int, int> get(int v) {
            return data[v];
        }
    };

    class UF {
    public:
        vector<int> parent;

        UF(int n):parent(n) {
            iota(parent.begin(), parent.end(), 0);
        }

        int find(int v) {
            if (parent[v] == parent[parent[v]]) {
                return parent[v];
            }
            return parent[v] = find(parent[v]);
        }

        void merge(int v, int w) {
            parent[find(v)] = find(w);
        }

        bool connedtd(int v, int w) {
            return find(v) == find(w);
        }
    };

    class Edge {
    public:
        Alloc* alloc;
        int v, w, weight;

        Edge(Alloc* alloc, int v, int w): alloc(alloc), v(v), w(w) {
            auto p1 = alloc->get(v);
            auto p2 = alloc->get(w);
            weight = abs(p1.first - p2.first) + abs(p1.second - p2.second);
        }

        size_t operator<(const Edge& other) const{
            return weight > other.weight;
        }
    };

    int minCostConnectPoints_kruskal(vector<vector<int>>& points) {
        Alloc alloc;
        for (auto& point: points) {
            alloc.alloc(point[0], point[1]);
        }
        priority_queue<Edge> pq;
        for (int i = 0; i < alloc.size(); i++) {
            for (int j = i + 1; j < alloc.size(); j++) {
                pq.emplace(&alloc, i, j);
            }
        }
        UF uf(alloc.size());
        int ans = 0;
        int ct = 0;
        while (!pq.empty() && ct + 1 < alloc.size()) {
            auto e = pq.top();
            pq.pop();
            if (uf.connedtd(e.v, e.w)) {
                continue;
            }
            ++ct;
            ans += e.weight;
            uf.merge(e.v, e.w);
        }
        return ans;
    }

    class xEdge {
    public:
        int v, w, weight;

        xEdge(int v, int w, int weight): v(v), w(w), weight(weight) {}

        size_t operator<(const xEdge& other) const{
            return weight < other.weight;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        Alloc alloc;
        for (auto& point: points) {
            alloc.alloc(point[0], point[1]);
        }
        auto dis = [&](int v, int w) {
            auto p1 = alloc.get(v);
            auto p2 = alloc.get(w);
            return abs(p1.first - p2.first) + abs(p1.second - p2.second);
        };
        vector<xEdge> vec;
        for (int i = 0; i < alloc.size(); i++) {
            for (int j = i + 1; j < alloc.size(); j++) {
                vec.emplace_back(i, j, dis(i, j));
            }
        }
        sort(vec.begin(), vec.end());

        // 需要使用并查集的原因是, 这个算法的中间态是 多个不连接的图
        // 而因为 prim 算法永远只有一个图, 所以 prim 算法可以用 marked[v] and marked[w]来判断
        UF uf(alloc.size());
        int ans = 0;
        int ct = 0;
        for (int idx = 0; ct < alloc.size() && idx < vec.size(); idx++) {
            auto& e = vec[idx];
            if (uf.connedtd(e.w, e.v)) {
                continue;
            }
            ++ct;
            ans += e.weight;
            uf.merge(e.v, e.w);
        }
        return ans;
    }

    int minCostConnectPoints_prim(vector<vector<int>>& points) {
        Alloc alloc;
        for (auto& point: points) {
            alloc.alloc(point[0], point[1]);
        }
        priority_queue<Edge> pq;
        vector<int> marked(alloc.size());

        auto visit = [&](int v) {
            if (marked[v]) {
                return;
            }
            marked[v] = 1;
            for (int w = 0; w < alloc.size(); w++) {
                if (v == w || marked[w]) {
                    continue;
                }
                pq.emplace(&alloc, v, w);
            }
        };
        visit(0);
        int ans = 0;
        int ct = 1;
        while (!pq.empty() && ct < alloc.size()) {
            auto e = pq.top();
            pq.pop();
            if (marked[e.v] and marked[e.w]) {
                continue;
            }
            ++ct;
            ans += e.weight;
            if (!marked[e.v]) {
                visit(e.v);
            }
            if (!marked[e.w]) {
                visit(e.w);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[0,0],[2,2],[3,10],[5,2],[7,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,12],[-2,5],[-4,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,1],[1,0],[-1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1000000,-1000000],[1000000,1000000]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0]]\n
// @lcpr case=end

 */

