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

// 欧拉函数
// 根据欧拉公式求
int Euler(int n) {
    int ans = n;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n != 1) ans = ans / n * (n - 1);
    return ans;
}


// 用线性筛求 1-n 内所有的欧拉函数
vector<int> Euler_phi(int n) {
    vector<int> vis(n + 1);
    vector<int> pri, phi(n + 1);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = i;
            pri.emplace_back(i);
            phi[i] = i - 1;
        }
        for (auto p: pri) {
            if (i * p > n) break;
            vis[i * p] = p;
            if (i % p == 0) {
                phi[i * p] = p * phi[i];
                break;
            }
            phi[i * p] = phi[p] * phi[i];
        }
    }
    return phi;
}

void phi_test() {
    mt19937 mt(random_device{}());
    uniform_int_distribution<int> u(0, 1e7);
    auto res = Euler_phi(1e7);
    for (int i = 0; i < 1000000; i++) {
        int n = u(mt);
        if (n >=  res.size()) {
            cout << "out of range" << endl;
            break;
        }
        if (res[n] != Euler(n)) {
            cout << n << "\t" << res[n] << ", " << Euler(n) << endl;
            break;
        }
    }
    cout << "done" << endl;
}


int main() {
    phi_test();
}
