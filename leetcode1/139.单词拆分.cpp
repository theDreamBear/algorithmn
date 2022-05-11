/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
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
class Solution {
   public:
    int cmp(const string& s, const string word, int pos) {
        if (pos + word.size() > s.size()) {
            return -1;
        }
        for (int i = 0; i < word.size(); i++) {
            if (s[pos + i] != word[i]) {
                return -1;
            }
        }
        return 0;
    }

    // 画下递归树， 发现有大量的重复
    bool dfs(const string& s, const vector<string>& wordDict, int pos) {
        if (pos >= s.size()) {
            return true;
        }
        for (auto& str : wordDict) {
            if (-1 == cmp(s, str, pos)) {
                continue;
            }
            if (dfs(s, wordDict, pos + str.size())) {
                return true;
            }
        }
        return false;
    }

    // 画下递归树， 发现有大量的重复, 增加备忘录
    bool dfs_memo(const string& s, const vector<string>& wordDict, int pos, unordered_map<int, bool>& memo) {
        if (pos >= s.size()) {
            return true;
        }
        if (memo.count(pos)) {
            return memo[pos];
        }
        bool end = false;
        for (auto& str : wordDict) {
            if (-1 == cmp(s, str, pos)) {
                continue;
            }
            if (dfs_memo(s, wordDict, pos + str.size(), memo)) {
                end = true;
                break;
            }
        }
        memo[pos] = end;
        return end;
    }

    bool wordBreak1(string s, vector<string>& wordDict) {
        // return dfs(s, wordDict, 0);
        unordered_map<int, bool> memo;
        return dfs_memo(s, wordDict, 0, memo);
    }

    // bfs 也可以

    // 动态规划
    // 1. 定义 dp[i][j] 是否可以被wordDict构成
    // 2. 结果 dp[0][s.size() - 1]
    // 3. 状态转移方程 dp[i][j] = dp[i][k] && dp[k + 1][j]
    // 4. 初始化
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        // 初始化
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string temp = s.substr(i, j - i + 1);
                if (words.count(temp)) {
                    dp[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (!dp[i][j]) {
                    for (int k = i; k < j; k++) {
                        if (dp[i][k] && dp[k + 1][j]) {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }

    // 上面的动态规划还可以优化， 继续优化中
};
// @lc code=end
