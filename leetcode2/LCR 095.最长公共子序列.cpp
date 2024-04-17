/*
 * @lc app=leetcode.cn id=LCR 095 lang=cpp
 * @lcpr version=30122
 *
 * [LCR 095] 最长公共子序列
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int longestCommonSubsequence_memo(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j)->int {
            if (i >= m || j >= n) {
                return 0;
            }
            if (memo[i][j] != -1) {
                return memo[i][j];
            }
            if (text1[i] == text2[j]) {
                return memo[i][j] = 1 + dfs(i + 1, j + 1);
            }
            return memo[i][j] = max(dfs(i + 1, j), dfs(i, j + 1));
        };
        return dfs(0, 0);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (tex)
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcde"\n"ace"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"def"\n
// @lcpr case=end

 */

