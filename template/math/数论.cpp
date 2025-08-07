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
// #include <cstdalign>
#include <cstdbool>
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

#define ll long long
// 随机
mt19937 mt(random_device{}());
uniform_int_distribution<ll> u;

// 快速幂_mod
ll fastMi(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll mod_mul(ll a, ll b, ll mod) {
    a = (a % mod + mod) % mod;
    b = (b % mod + mod) % mod;
    ll ans = 0;
    while (b) {
        if (b & 1) {
            ans = (ans + a) % mod;
        }
        b >>= 1;
        a = (a + a) % mod;
    }
    return ans;
}

ll fastMi2(ll a, ll b, ll mod) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) ans = mod_mul(ans, a, mod);
        a = mod_mul(a, a, mod);
        b >>= 1;
    }
    return ans;
}

// 求逆, 费马小定理
ll mod_inverse(ll b, ll mod) {
    return fastMi(b, mod - 2, mod);
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 组合数
// c(n, k, mod)

// 1 杨辉三角
void init_yanghuisanjiao() {
    const ll N = 300;
    const ll mod = 1e9 + 7;
    vector<vector<ll>> f(N + 1, vector<ll>(N + 1));
    for (ll i = 1; i < N; i++) {
        f[i][0] = f[i][i] = 1;
        for (ll j = 1; j < i; j++) {
            // 这个可以用动态规划选或者不选来理解
            // c(i, j) 选j 位置的 有 c(i - 1, j - 1)
            //         不选位置的 有 c(i - 1, j)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % mod;
        }
    }

    // 测试部分***************************
    // 暴力测试
    auto brute = [&](ll n, ll k) {
        ll ans = 1;
        for (ll i = 1; i <= k; i++) {
            ans = (ans * (n - i + 1)) / i;
        }
        return ans;
    };

    // 利用逆来求
    vector<ll> inverse(N, 1), p(N, 1);
    for (ll i = 1; i < N; i++) {
        p[i] = (p[i - 1] * i) % mod;
    }

    inverse[N - 1] = fastMi(p[N - 1], mod - 2, mod);
    for (ll i = N - 2; i >= 0; i--) {
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
    }

    auto get = [&](ll n, ll k) {
        return (p[n] * inverse[k]) % mod * inverse[n - k] % mod;
    };

    for (ll i = 1; i < 5; i++) {
        for (ll j = 0; j <= i; j++) {
            if (f[i][j] != get(i, j)) {
                cout << "(" << i << "," << j << ") = " << f[i][j] << "------" << get(i, j) << endl;
            }
        }
    }
    cout << "ok" << endl;
}

// 使用逆来求组合数
void Comb(ll n, ll k, ll mod) {
    const ll N = 301;
    vector<ll> inverse(N, 1), p(N, 1);
    for (ll i = 1; i < N; i++) {
        p[i] = (p[i - 1] * i) % mod;
    }

    inverse[N - 1] = fastMi(p[N - 1], mod - 2, mod);
    for (ll i = N - 2; i >= 0; i--) {
        inverse[i] = (inverse[i + 1] * (i + 1)) % mod;
    }

    auto get = [&](ll n, ll k) {
        return (p[n] * inverse[k]) % mod * inverse[n - k] % mod;
    };
}

// 矩阵乘法
#define type ll
#define matrix vector<vector<type>>

matrix operator*(const matrix& a, const matrix& b) {
    assert(a.size() and b.size() and a[0].size() == b.size());
    ll m = a.size(), n = b.size(), mn = b[0].size();
    matrix c(m, vector<type>(mn));
    for (ll i = 0; i < m; i++) {
        for (ll t = 0; t < n; t++) {
            if (a[i][t] == 0) continue;
            for (ll j = 0; j < mn; j++) {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    return c;
}

matrix fastMatrix(const matrix& a, ll n) {
    if (n == 1) {
        ll m = a.size();
        matrix ans(m, vector<type>(m));
        for (ll i = 0; i < m; i++) ans[i][i] = 1;
        return ans;
    }
    matrix ans = a;
    matrix base = a;
    n--;
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans;
}
#undef type

void mul_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(1e12, 1e18);
    ll mod = 1e9 + 7;
    for (ll i = 0; i < 10000; i++) {
        ll a = u(mt), b = u(mt);
        if (fastMi(a, b, mod) != fastMi2(a, b, mod)) {
            cout << a << "\t" << b << endl;
            return;
        }
    }
}

tuple<ll, ll, ll> getMinPossitiveX(ll a, ll b) {
    ll x, y;
    ll d = exgcd(a, b, x, y);
    x *= d;
    ll delta = b / d;
    x = (x  + delta) % delta;
    y = (1 - a * x) / b;
    return {x, y, d};
}

void test_exgcd() {
     for (ll i = 0; i < 30; i++) {
        ll a = u(mt) % 100 + 1;
        ll b = u(mt) % 100 + 1;
        if (gcd(a, b) == 1) {
            ll c = u(mt) % 20 + 1;
            auto [x, y, d] = getMinPossitiveX(a, b);
            if (a * x + b * y != 1) {
                cout << "(" << a << "," << b << "," << c << ") = " << x << ", " << y << "," << d << endl;
            }
        }
    }
}

// 中国剩余定理
// 这个解法要求 a 的每个数, 两两互质
ll Chinese_Left(vector<ll>& a, vector<ll>& b) {
    ll M = 1;
    for (auto v: a) {
        M *= v;
    }
    ll ans = 0;
    for (ll i = 0; i < b.size(); i++) {
        ll m1 = M / a[i];
        ll m2 = mod_inverse(m1, a[i]);
        ans = (ans + b[i] * m1 * m2) % M;
    }
    return ans;
}

// 迭代法
ll Chinese_Left_Ite(vector<ll>& ms, vector<ll>& as) {
    ll m1 = ms[0], a1 = as[0];
    ll x, y, ans;
    for (ll i = 1; i < ms.size(); i++) {
        ll m2 = ms[i], a2 = as[i];
        ll a = m1, b = m2, c = ((a2 - a1) % m2 + m2) % m2;
        ll d = exgcd(a, b, x, y);
        if (c % d != 0) {
            return -1;
        }
        ll x1 = mod_mul(x, c / d, b / d);
        ans = m1 * x1 + a1;
        m1 = m1 / gcd(m1, m2) * m2;
        a1 = (ans % m1 + m1) % m1;
        ans = a1;
    }
    return ans;
}

void Chinese_Left_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(0, 1e2);
    for (ll i = 0; i < 20; i++) {
        vector<ll> a, b;
        for (ll j = 0; j < 3; j++) {
            a.push_back(u(mt) + 2);
            b.push_back(rand() % a.back());
            cout << "(" << a.back() << "," << b.back() << ")=";
        }
        ll x = Chinese_Left_Ite(a, b);
        if (x == -1) {
            cout << "-1" << endl;
            continue;
        }
        cout << x << endl;
        for (ll j = 0; j < a.size(); j++) {
            if (x % a[j] != b[j]) {
                cout << "bad" << endl;
                return;
            }
        }
    }
    cout << "success" << endl;
}


int main() {
    Chinese_Left_test();
}
