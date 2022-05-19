/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
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
// @lc code=start
// 超时 case 66
class Solution1 {
   private:
    vector<int> data;

   public:
    Solution1(int n, vector<int>& blacklist) {
        unordered_set<int> black(blacklist.begin(), blacklist.end());
        for (int i = 0; i < n; i++) {
            if (black.count(i) == 0) {
                data.push_back(i);
            }
        }
    }

    int pick() {
        int n = rand() % data.size();
        return data[n];
    }
};

// 超时case 65
class Solution2 {
   private:
    unordered_set<int> black;
    int n;

   public:
    Solution2(int n, vector<int>& blacklist) : black(blacklist.begin(), blacklist.end()), n(n) {}

    int pick() {
        int val = 0;
        do {
            val = rand() % n;
        } while (black.count(val) > 0);
        return val;
    }
};

// 有个二分法
// 后续研究下

class Solution_best {
   private:
    unordered_map<int, int> black_mapping;
    int sz;

   public:
    Solution_best(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        for (auto b : blacklist) {
            black_mapping[b] = 1;
        }
        int lastValue = n - 1;
        int firstValue = sz;
        for (auto b : blacklist) {
            if (b >= firstValue) {
                continue;
            }
            while (black_mapping.count(lastValue)) {
                --lastValue;
            }
            black_mapping[b] = lastValue;
            --lastValue;
        }
    }

    int pick() {
        int val = rand() % sz;
        if (black_mapping.count(val)) {
            return black_mapping[val];
        }
        return val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
