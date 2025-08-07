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
#include <ranges>
#include "timer.h"
#define ll long long

// 随机
mt19937 mt(random_device{}());
uniform_int_distribution<int> u;

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
    a %= mod;
    b %= mod;
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

int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// 埃氏筛
void aishishan() {
    int n = 1e5;
    vector<int> is(n, 1);
    is[0] = is[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (is[i]) {
            for (int j = i * i; j < n; j += i) is[i] = 0;
        }
    }
}

// 欧拉筛, 记录最小公因子
void EulerShai() {
    int n = 1e7;
    vector<int> vis(n), pr;
    for (int i = 2; i < n; i++) {
        if (!vis[i]) {
            pr.emplace_back(i);
            vis[i] = i;
        }
        for (int j = 0; j < pr.size(); j++) {
            if (i * pr[j] >= n) break;
            vis[i * pr[j]] = pr[j];
            if (i * pr[j] == 0) break;
        }
    }
}

// 判断是不是素数, 试除法
bool isPrime(ll n) {
    if (n == 0 or n == 1) return false;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            //cout << i << endl;
            return false;
        }
    }
    return true;
}


// a^2 % p = 1, 若 p 为素数, 则 a % p = 1 或者 a % p = p - 1
// 若出现 不满足的, 则 p 为非素数
bool witness(ll a, ll n) {
    ll t = 0, u = n - 1;
    while ((u & 1) == 0) {
        t++;
        u >>= 1;
    }
    auto x1 = fastMi(a, u, n);
    for (int i = 0; i < t; i++) {
        auto x2 = fastMi(x1, 2, n);
        if (x2 == 1 and x1 != 1 and x1 != (n - 1)) return false;
        x1 = x2;
    }
    // 费马小定理
    return x1 == 1;
}

bool isPrime_miller_rabin(ll n) {
    if (n < 2) return false;
    if (n  == 2) return true;
    if (n % 2 == 0) return false;
    int s = 50;
    for (int i = 0; i < s and i < n; i++) {
        int a = rand() % (n - 1) + 1;
        if (!witness(a, n)) return false;
    }
    return true;
}

// 求公因子
// 试除法求因子
void tryFindDivsor(ll n, vector<ll>& divs, vector<ll>& cnt) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divs.emplace_back(i), cnt.emplace_back(0);
            while (n % i == 0) {
                n /= i;
                cnt.back()++;
            }
        }
    }
    if (n != 1) {
        divs.emplace_back(n);
        cnt.emplace_back(1);
    }
}

// 启发式搜索求公因子
// x2 = (x1 ^ 2 + c) % p
// d = gcd(abs(y - x2, p)), d != 1 则 d 为 p 的因子
void find_fac(ll n, vector<ll>& ans) {
    if (isPrime_miller_rabin(n)) {
        ans.push_back(n);
        return;
    }
    auto pollard = [&](ll n)->ll {
        ll t = 1, k = 2;
        ll c = rand() % (n - 1) + 1;
        ll x = rand() % n;
        ll y = x;
        while (true) {
            ++t;
            x = (mod_mul(x, 2, n) + c) % n;
            ll d = gcd(abs(y - x), n);
            if (d != 1 and d != n) return d;
            if (y == x) return n;
            if (t == k) {
                y = x;
                k <<= 1;
            }
        }
    };

    ll p = n;
    while (p >= n) p = pollard(n);
    find_fac(p, ans);
    find_fac(n / p, ans);
}

void mul_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(1e8, 1e9);
    ll mod = 1e9 + 7;
    for (int i = 0; i < 10000; i++) {
        ll a = u(mt), b = u(mt);
        if (fastMi(a, b, mod) != fastMi2(a, b, mod)) {
            cout << a << "\t" << b << endl;
            return;
        }
    }
}

void primer_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(1e18, LLONG_MAX);
    for (int i =  0; i < 1000; i++) {
        ll n = u(mt);
        //if (isPrime_miller_rabin(n)) {
        if (isPrime(n) != isPrime_miller_rabin(n)) {
            cout << n << "\t" << isPrime(n) << ", " << isPrime_miller_rabin(n) << endl;
            //return;
            //}
        }
    }
}

void fac_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<ll> u(1e17, 1e18);
    MyTimer t1, t2;
    ll c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    t2.start();
    for (int i = 0; i < 10; i++) {
        ll n = u(mt);
        vector<ll> a, b, c;

        t1.start();
        tryFindDivsor(n, a, b);
        t1.stop();
        c1 += t1.elapse();

        t1.start();
        find_fac(n, c);
        t1.stop();
        c2 += t1.elapse();

        t1.start();
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        if (a != c) {
            cout << "bad" << endl;
        }
        t1.stop();
        c3 += t1.elapse();
    }
    t2.stop();
    c4 = t2.elapse();
    cout << "试除法耗时: " << c1 << "us" << endl;
    cout << "启发式耗时: " << c2 << "us" << endl;
    cout << "other耗时: " << c3 << "us" << endl;
    cout << "tatal耗时: " << c4 << "us" << endl;
    cout << "done" << endl;
}

int main() {
    fac_test();
}
