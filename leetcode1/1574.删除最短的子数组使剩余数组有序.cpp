/*
 * @lc app=leetcode.cn id=1574 lang=cpp
 *
 * [1574] 删除最短的子数组使剩余数组有序
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
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
// @lc code=start
class Solution {
   public:
    // [left, right] 区间
    bool check(vector<int>& arr, int left, int right) {
        int pre = INT_MIN;
        for (int i = 0; i < left; i++) {
            if (pre > arr[i]) {
                return false;
            }
            pre = arr[i];
        }
        for (int i = right + 1; i < arr.size(); i++) {
            if (pre > arr[i]) {
                return false;
            }
            pre = arr[i];
        }
        return true;
    }

    // [0, left) 左边符合区域
    // (right, size] 右边符合区域

    // [left, right] 消除区间
    int findLengthOfShortestSubarray_timeout(vector<int>& arr) {
        if (arr.size() <= 1) {
            return 0;
        }
        int ans = arr.size() - 1;
        int pre = INT_MIN;
        int after = INT_MAX;

        for (int left = 0; left < arr.size(); left++) {
            // 左边
            if (left > 0) {
                if (pre > arr[left - 1]) {
                    return ans;
                }
                pre = arr[left - 1];
            }
            // 右边逆序
            int right = arr.size() - 1;
            for (; right >= left; right--) {
                if (arr[right] < pre || arr[right] > after) {
                    break;
                }
                after = arr[right];
            }
            ans = min(ans, right - left + 1);
        }
        return ans;
    }

    // (left, right) 消除区间
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if (arr.size() <= 1) {
            return 0;
        }
        int ans = arr.size() - 1;
        int pre = INT_MIN;
        int after = INT_MAX;
        // 左边非递减区间
        int left = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < pre) {
                break;
            }
            pre = arr[i];
            ++left;
        }
        if (left + 1 == arr.size()) {
            return 0;
        }
        ans = min(ans, (int)arr.size() - left - 1);
        // 右边
        int right = arr.size();
        for (int i = arr.size() - 1; i >= left; i--) {
            if (arr[i] > after) {
                break;
            }
            after = arr[i];
            --right;
        }
        ans = min(ans, (int)right);
        for (int x = left; x >= 0; x--) {
            int val = arr[x];
            auto pos = lower_bound(arr.begin() + right, arr.end(), val);
            int v = pos - (arr.begin() + x) - 1;
            ans = min(ans, v);
        }

        return ans;
    }
};
// @lc code=end

