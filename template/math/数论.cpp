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
#include <random>
using namespace std;

// 随机
mt19937 mt(random_device{}());
uniform_int_distribution<int> u;

// 快速幂_mod
long long fastMi(long long a, long long b, long long mod) {
    long long ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

// 求逆, 费马小定理
int mod_inverse(int b, int q, int mod) {
    return fastMi(b, q - 2, mod);
}

// 组合数
// c(n, k, mod)

// 1 杨辉三角
void init_yanghuisanjiao() {
    const int N = 300;
    const int mod = 1e9 + 7;
    vector<vector<long long>> f(N + 1, vector<long long>(N + 1));
    for (int i = 1; i < N; i++) {
        f[i][0] = f[i][i] = 1;
        for (int j = 1; j < i; j++) {
            // 这个可以用动态规划选或者不选来理解
            // c(i, j) 选j 位置的 有 c(i - 1, j - 1)
            //         不选位置的 有 c(i - 1, j)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
        }
    }

    // 测试部分***************************
    // 暴力测试
    auto brute = [&](int n, int k) {
        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            ans = (ans * (n - i + 1)) / i;
        }
        return ans;
    };

    // 利用逆来求
    vector<long long> inverse(N, 1), p(N, 1);
    for (int i = 1; i < N; i++) {
        p[i] = (p[i - 1] * i) % mod;
    }

    inverse[N - 1] = fastMi(p[N - 1], mod - 2, mod);
    for (int i = N - 2; i >= 0; i--) {
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
    }

    auto get = [&](int n, int k) {
        return (p[n] * inverse[k]) % mod * inverse[n - k] % mod;
    };

    for (int i = 1; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (f[i][j] != get(i, j)) {
                cout << "(" << i << "," << j << ") = " << f[i][j] << "------" << get(i, j) << endl;
            }
        }
    }
    cout << "ok" << endl;
}

// 使用逆来求 组合数
void Comb(int n, int k, int mod) {
    const int N = 301;
    vector<long long> inverse(N, 1), p(N, 1);
    for (int i = 1; i < N; i++) {
        p[i] = (p[i - 1] * i) % mod;
    }

    inverse[N - 1] = fastMi(p[N - 1], mod - 2, mod);
    for (int i = N - 2; i >= 0; i--) {
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
    }

    auto get = [&](int n, int k) {
        return (p[n] * inverse[k]) % mod * inverse[n - k] % mod;
    };
}



int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

tuple<int, int, int> getMinPossitiveX(int a, int b) {
    int x, y;
    int d = exgcd(a, b, x, y);
    x *= d;
    int delta = b / d;
    x = (x  + delta) % delta;
    y = (1 - a * x) / b;
    return {x, y, d};
}

void test_exgcd() {
     for (int i = 0; i < 30; i++) {
        int a = u(mt) % 100 + 1;
        int b = u(mt) % 100 + 1;
        if (gcd(a, b) == 1) {
            int c = u(mt) % 20 + 1;
            auto [x, y, d] = getMinPossitiveX(a, b);
            if (a * x + b * y != 1) {
                cout << "(" << a << "," << b << "," << c << ") = " << x << ", " << y << "," << d << endl;
            }
        }
    }
}

int main() {
    init_yanghuisanjiao();
}
