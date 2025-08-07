// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;

// dijkstra
// 适用范围: 不能负边
// 适用于稠密图
// 顶点数等于 n, 边数等于 e
// 复杂度 n^2
vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    const int inf = INT_MAX / 2;
    vector<int> dis(n, inf), closed(n);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!closed[j] and (v == -1 or dis[j] < dis[v])) {
                v = j;
            }
        }
        if (v == -1) {
            return dis;
        }
        closed[v] = 1;
        for (auto& [to, c]: g[v]) {
            if (c + dis[v] < dis[to]) {
                dis[to] = c + dis[v];
            }
        }
    }
    return dis;
}

// dijkstra
// 适用范围: 不能负边
// 适用于稀疏图
// 顶点数等于 n, 边数等于 e
// 复杂度 nlge
vector<int> dijkstra_pq(vector<vector<pair<int, int>>>& g, int s) {
    int n = g.size();
    const int inf = INT_MAX / 2;
    vector<int> dis(n, inf), closed(n);
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (dis[u] < c) continue;
        for (auto& [to, c2]: g[u]) {
            if (c + c2 < dis[to]) {
                dis[to] = c + c2;
                pq.emplace(dis[to], to);
            }
        }
    }
    return dis;
}

// bf算法
// 优点, 可以检测到负环
vector<int> bf(vector<vector<int>>& g, int n, int s) {
    vector<int> dis(n, INT_MAX / 2);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g.size(); j++) {
            int u = g[j][0], v = g[j][1], c = g[j][2];
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }
    return dis;
}

// 判断负环
bool bf_judge(vector<vector<int>>& g, int n, int s) {
    vector<int> dis(n, INT_MAX / 2);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g.size(); j++) {
            int u = g[j][0], v = g[j][1], c = g[j][2];
            if (dis[u] + c < dis[v]) {
                if (i + 1 == n) {
                    // 最后一轮还有更新
                    return true;
                }
                dis[v] = dis[u] + c;
            }
        }
    }
    return false;
}

// spfa
vector<int> spfa(vector<vector<pair<int, int>>>& g, int s) {
    vector<int> vis(g.size(), INT_MAX / 2), onstack(g.size());
    vis[s] = 0;
    queue<int> q;
    q.push(s);
    onstack[s] = 1;
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        onstack[u] = 0;
        for (auto& [v, c]: g[u]) {
            if (dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
                if (!onstack[v]) {
                    onstack[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return vis;
}

// floyd
vector<int> floyd(vector<vector<int>>& edges, int n, int s) {
    vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; i++) {
        g[i][i] = 0;
    }
    for (auto e: edges) {
        int u = e[0], v = e[1], c = e[2];
        g[u][v] = c;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = g[s][i];
    }
    return ans;
}