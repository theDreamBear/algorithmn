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

#define ll long long

// 唯一解高斯消元求解
vector<double> gauss_unique(vector<vector<double>>& arr) {
    vector<vector<double>> a = arr;
    assert(a.size() and a[0].size() and a.size() + 1 == a[0].size());
    double eps = 1e-7;
    int m = a.size(), n = a[0].size();
    for (int j = 0; j < m; j++) {
        int i = j;
        // i, j
        for (int k = i + 1; k < m; k++) {
            // (k, j)
            if (fabs(a[i][j]) < fabs(a[k][j])) {
                i = k;
            }
        }
        if (i != j) swap(a[i], a[j]);
        if (fabs(a[j][j]) < eps) {
            // 没有唯一解
            throw;
        }
        // 变成 1
        for (int k = n - 1; k >= 0; k--) {
            a[j][k] /= a[j][j];
        }
        for (int k = 0; k < m; k++) {
            if (k != j) {
                // a[k][j]
                double mul = a[k][j];
                for (int t = 0; t < n; t++) {
                    a[k][t] -= a[j][t] * mul;
                }
            }
        }
    }
    vector<double> ans(m);
    for (int i = 0; i < m; i++) ans[i] = a[i][n - 1];
    // check_valid
    // for (int i = 0; i < m; i++) {
    //     double res = 0;
    //     for (int j = 0; j + 1 < n; j++) {
    //         res += arr[i][j] * ans[j];
    //     }
    //     if (fabs(res - arr[i][n - 1]) >= eps) {
    //         throw;
    //     }
    // }
    return ans;
}

void gauss_test() {
    vector<vector<double>> a{
        {1.2, 0.3, 0.4, 0.5, 0.6, 0.7, 8.1},
        {0.8, 1.6, 0.9, 1.1, 1.3, 1.5, 12.5},
        {1.4, 1.7, 2.0, 1.8, 1.9, 2.1, 17.9},
        {2.2, 2.5, 2.8, 3.0, 2.9, 3.1, 24.5},
        {3.2, 3.5, 3.8, 4.1, 4.4, 4.7, 33.7},
        {5.0, 5.3, 5.6, 5.9, 6.2, 6.5, 49.5},
    };
    auto res = gauss_unique(a);
    for (auto v: res) {
        cout << v << "\t";
    }
    cout << endl;
}

// 求异或线性基
// 动态添加
class XOR_Insert {
public:
    const int M = 63;
    vector<ll> a;
    bool zero = false;

    void insert(int x) {
        for (int i = M; i >= 0; i--) {
            if (x >> i == 1) {
                if (a[i] == 0) {
                    a[i] = x;
                    return;
                } else {
                    x ^= a[i];
                }
            }
        }
        zero = true;
    }

    ll qmax() {
        ll ans = 0;
        for (int i = M; i >= 0; i--) {
            ans = max(ans, ans ^ a[i]);
        }
        return ans;
    }
};

class XOR_Base {
public:
    int n = 0;
    bool zero = false;
    vector<ll> a;

    XOR_Base(vector<ll>& b): a(b) {
        int m = a.size();
        int i = 0;
        for (ll j = 1ll << 62; i < m and j; j >>= 1) {
            // 找1个
            int k = i;
            for (; k < m; k++) {
                if (a[k] & j) {
                    break;
                }
            }
            if (k >= m) continue;
            swap(a[i], a[k]);
            for (int t = 0; t < m; t++) {
                if (t != i and a[t] & j) {
                    a[t] ^= a[i];
                }
            }
            i++;
        }
        if (i != m) zero = true;
        n = i;
    }

    ll query(int rk) {
        ll ans = 0;
        if (zero) rk--;
        if (!rk) return 0;
        for (int i = n - 1; i >= 0; i--) {
            if (rk & 1) ans ^= a[i];
            rk >>= 1;
        }
        if (rk) return -1;
        return ans;
    }

    vector<ll> get_base() {
        return vector<ll>(a.begin(), a.begin() + n);
    }
};

vector<ll> get_random_vec(int n) {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(0, 1e7);
    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = u(mt);
    }
    return ans;
}

void XOR_test() {
    for (int i = 0; i < 1; i++) {
        auto a = get_random_vec(5);
        XOR_Base x(a);
        for (auto v: a) {
            cout << v << "\t";
        }
        cout << endl << endl;;
        for (auto v: x.get_base()) {
            cout << v << "\t";
        }
        cout << endl;
    }
}

int main() {
    XOR_test();
}