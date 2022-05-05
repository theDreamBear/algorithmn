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
/*
 * @lc app=leetcode.cn id=2218 lang=cpp
 *
 * [2218] 从栈中取出 K 个硬币的最大面值和
 */

// @lc code=start
class Solution {
    unordered_map<int, int> res;

   public:
    int dfs(int i, int left, vector<vector<int>>& prefixSum, int indent) {
        int v = i * 20000 + left;
        if (res.count(v)) {
            return res[v];
        }
        if (left == 0) {
            return 0;
        }
        if (i >= prefixSum.size()) {
            return 0;
        }
        int sum = 0;
        // 取l个
        for (int l = 0; l < prefixSum[i].size() && l <= left; l++) {
            int temp = dfs(i + 1, left - l, prefixSum, indent + 1);
            sum = max(sum, prefixSum[i][l] + temp);
        }
        res[v] = sum;
        return sum;
    }

    int maxValueOfCoinsDfs(vector<vector<int>>& piles, int k) {
        vector<vector<int>> prefixSum;
        for (int i = 0; i < piles.size(); i++) {
            vector<int> temp(piles[i].size() + 1);
            partial_sum(piles[i].begin(), piles[i].end(), ++temp.begin());
            prefixSum.push_back(temp);
        }
        return dfs(0, k, prefixSum, 0);
    }

    // 背包前i个取 j 的 最大值
    // dp[i][j] = max(dp[i - 1][j - x] + prefixSum[i - 1][x])
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> prefixSum;
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1));
        for (int i = 0; i < piles.size(); i++) {
            vector<int> temp(piles[i].size() + 1);
            partial_sum(piles[i].begin(), piles[i].end(), ++temp.begin());
            prefixSum.push_back(move(temp));
        }
        for (int i = 1; i <= piles.size(); i++) {
            for (int j = 1; j <= k; j++) {
                for (int x = 0; x <= piles[i - 1].size() && x <= j; x++) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + prefixSum[i - 1][x]);
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
