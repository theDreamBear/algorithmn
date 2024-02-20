/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * @lcpr version=30116
 *
 * [10] 正则表达式匹配
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
        1 <= s.length <= 20
        1 <= p.length <= 20
        s 只包含从 a-z 的小写字母。
        p 只包含从 a-z 的小写字母，以及字符 . 和 *。
        保证每次出现字符 * 时，前面都匹配到有效的字符
    */

    /*
        状态：      dp[i][j] p的前i个字符和s的前j个字符是否匹配
        初始化:     dp[0][0] = true
                   dp[0][1....] = false;
        状态转移方程  i + 1 < m and p[i + 1] == '*'
                        while (p[i] == s[j] and j < n) {
                            dp[i + 1][j + 1] = 1;
                            j++;
                        }
                        i += 2;
                    else:
                        p[i] == s[j] dp[i + 1][j + 1] = dp[i][j]




    */
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        return dp.back().back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aa"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"a*"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n".*"\n
// @lcpr case=end

 */

