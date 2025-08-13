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

// 问题
// decltype(true? a: b) 有问题
// decltype(true? a: b) 可能会返回引用类型
// template<typename T1, typename T2>
// auto max1(T1 a, T2 b)->decltype(true? a: b) {
//     return a < b ? a : b;
// }

// void max1_test() {
//     int a = 1, b = 2;
//     auto& c = ::max1(a, b);
//     c++;
//     cout << a << "\t" << b << "\t" << c << endl;
// }

// 问题
// decltype(true? a: b) 有问题
// 使用 decay 去掉引用
template<typename T1, typename T2>
auto max2(T1 a, T2 b)-> decay_t<decltype(true? a: b)> {
    return a < b ? a : b;
}

//
template<typename T1, typename T2, typename RT = common_type_t<T1, T2>>
RT max2(T1 a, T2 b) {
    return a < b ? a : b;
}

char const*  max(char const* a, char const* b) {
    //cout << (long long)&a << "\t" << (long long)&b << endl;
    return strcmp(a, b) < 0 ? a: b;
}

// 指针也是按值传递的, 这样写 max 函数, 能更快的找到问题
// char const  max(char const a, char const b) {
//     //cout << (long long)&a << "\t" << (long long)&b << endl;
//     return a < b ? a: b;
// }

// returning reference to local temporary object
template<typename T>
T const& max(T const& a, T const& b, T const& c) {
    //cout << (long long)&a << "\t" << (long long)&b << "\t" << (long long)&c<< endl;
    return max(max(a, b), c);
}


int max_test_2_main() {
    char const* a = "123";
    char const* b = "234";
    char const* c = "345";
    auto&& d = max(a, b, c);
    cout << &d << endl;
    // 自改栈内值
    for (int i = 0; i < 100; i++) {
        cout << i << "\t";
    }
    cout << endl;
    // 这时候会栈内引用出问题了
    printf("%s\n", d);
    return 0;
}


