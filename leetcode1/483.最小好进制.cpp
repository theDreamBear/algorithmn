/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */
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
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#include <cmath>
// @lc code=start
/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */
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
#include <type_traits>
#include <typeindex>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
#include <cmath>
// @lc code=start
class Solution {
   public:
    bool isGoodBase(long long base, long long val) {
        while (val) {
            long long mod = val % base;
            if (mod != 1) {
                return false;
            }
            val /= base;
        }
        return true;
    }

    string smallestGoodBase_violate(string n) {
        long long val = strtoll(n.c_str(), NULL, 10);
        long long i = 2;
        for (; i < val; i++) {
            if (val % i == 0) {
                continue;
            }
            if (isGoodBase(i, val)) {
                break;
            }
        }
        return to_string(i);
    }

    long long nbaseVal(long long base, long long m) {
        unsigned long long sum = 0;
        unsigned long long multiy = 1;
        for (int i = 0; i < m; i++) {
            sum += multiy;
            if (i + 1 < m) {
                multiy *= base;
            }
        }
        return sum;
    }

    string smallestGoodBase(string n) {
        unsigned long long val = strtoll(n.c_str(), NULL, 10);
        for (long long m = log(val + 1) / log(2) + 1; m > 1; m--) {
            long long left = 2;
            long long right = pow(val, 1.0 / (m - 1)) + 1;
            while (left + 1 < right) {
                long long mid = (right - left) / 2 + left;
                auto sum = nbaseVal(mid, m);
                if (sum > val) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            auto sum = nbaseVal(left, m);
            if (sum == val) {
                return to_string(left);
            }
            sum = nbaseVal(right, m);
            if (sum == val) {
                return to_string(right);
            }
        }
        return to_string(val - 1);
    }
};
// @lc code=end
