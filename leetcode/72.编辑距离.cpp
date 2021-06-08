/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <numeric>

// @lc code=start
using namespace std;

template<typename T, class F>
auto operator|(T &&param, F &&f) -> decltype(std::forward<F>(f)(std::forward<T>(param))) {
    return (std::forward<F>(f)(std::forward<T>(param)));
}

constexpr int MAX_N = 501;
int dp[MAX_N][MAX_N];

/*

*/
auto minDistanceHelper = [](string str) {
    stringstream ss(str);
    string s1, s2;
    ss >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    return dp[m][n];
};

class Solution {
public:

    int minDistance(string word1, string word2) {
        return word1 + " " + word2 | minDistanceHelper;
    }
};
// @lc code=end

int main() {
    cout << Solution{}.minDistance("horse", "ros");
}
