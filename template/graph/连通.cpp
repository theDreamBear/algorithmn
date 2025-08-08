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

using ll = long long;
using vi = vector<int>;

// 无向图
// 割点
vector<int> find_cut_point(vector<vector<int>>& g) {
    int n = g.size();
    vi low(n), num(n);
    int dfn = 0, root = 0;
    vector<int> ans;
    auto dfs = [&](auto&& dfs, int u, int fa)->void {
        num[u] = low[u] = ++dfn;
        int child = 0;
        for (auto v: g[u]) {
            // tree边
            if (!num[v]) {
                ++child;
                dfs(dfs, v, u);
                // 割点
                if (low[v] >= num[u] and u != root) {
                    ans.emplace_back(u);
                }
                low[u] = min(low[u], low[v]);
            // back边
            } else if (v != fa) {
                low[u] = min(low[u], num[v]);
            }
        }
        if (u == root and child >= 2) {
            ans.emplace_back(u);
        }
    };
    dfs(dfs, root, -1);
    return ans;
}

// 无线图
// 割边
vector<pair<int, int>> find_cut_edge(vector<vector<int>>& g) {
    int n = g.size();
    vi low(n), num(n);
    int dfn = 0, root = 0;
    vector<pair<int, int>> ans;
    auto dfs = [&](auto&& dfs, int u, int fa)->void {
        num[u] = low[u] = ++dfn;
        for (auto v: g[u]) {
            // tree边
            if (!num[v]) {
                dfs(dfs, v, u);
                // 割点
                if (low[v] > num[u]) {
                    ans.emplace_back(min(u, v), max(u, v));
                }
                low[u] = min(low[u], low[v]);
            // back边
            } else if (v != fa) {
                low[u] = min(low[u], num[v]);
            }
        }
    };
    dfs(dfs, root, -1);
    return ans;
}

// 无向图
// 点双连通分量, 去掉任一点, 其他点都是连通的
//


// 无向图
// 边双连通分量, 去掉任一边, 其他点都能保持连通
class TarJan_edge{
public:

};