/*
 * @lc app=leetcode.cn id=72 lang=cpp
 * @lcpr version=30116
 *
 * [72] 编辑距离
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
    /*
        0 <= word1.length, word2.length <= 500
        word1 和 word2 由小写英文字母组成
    */
    /*
        状态： dp[m][n] w1前m个字符编辑成w2的前n个字符的最少操作少
        初始化
            dp[0][0] = 0
            dp[0][1...i] = i;
            dp[1..i][0] = i;
        状态转移
            w1[i] == w2[j] dp[i][j] = dp[i - 1][j - 1];
            or dp[i][j]
            min(
                删除 dp[i - 1][j] + 1
                替换 dp[i - 1][j - 1] + 1
                插入 dp[i][j - 1] + 1
            )
    */
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i][j], dp[i + 1][j]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "horse"\n"ros"\n
// @lcpr case=end

// @lcpr case=start
// "intention"\n"execution"\n
// @lcpr case=end

 */

