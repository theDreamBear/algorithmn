/*
 * @lc app=leetcode.cn id=2801 lang=cpp
 * @lcpr version=30204
 *
 * [2801] 统计范围内的步进数字数目
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
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    const int mod = 1e9 + 7;
    int cal(string highValue) {
        long long dp[2][2][10][110];
        memset(dp, -1, sizeof(long long) * 2 * 2 * 10 * 110);

        auto dfs = [&](auto&& dfs, int isNum, int isHigh, int last, int pos)->int {
            if (pos >= highValue.size()) {
                return isNum;
            }
            auto& ans = dp[isNum][isHigh][last][pos];
            if (ans != -1) {
                return ans;
            }
            int low = 1 - isNum;
            int high = isHigh ? highValue[pos] - '0': 9;
            if (!isNum) {
                ans = dfs(dfs, 0, 0, 0, pos + 1);
                for (int x = low; x <= high; x++) {
                    ans = (ans + dfs(dfs, 1, isHigh and x + '0' == highValue[pos], x, pos + 1)) % mod;
                }
            } else {
                ans = 0;
                for (int x = max(0, last - 1); x <= min(last + 1, high); x++) {
                    if (x == last) continue;
                    ans = (ans + dfs(dfs, 1, isHigh and x + '0' == highValue[pos], x, pos + 1)) % mod;
                }
            }
            return ans;
        };
        return dfs(dfs, 0, 1, 0, 0);
    }

    string str_sub(string s) {
        int n = s.size();
        int i = n - 1;
        while (i >= 0 and s[i] == '0') i--;
        --s[i];
        for (int j = i + 1; j < n; j++) {
            s[j] = '9';
        }
        return s;
    }

    bool valid(string &s) {
        for (int i = 1; i < s.length(); i++)
            if (abs(int(s[i]) - int(s[i - 1])) != 1)
                return false;
        return true;
    }

    int countSteppingNumbers(string low, string high) {
        // return (cal(high) - cal(str_sub(low)) + mod) % mod;
        return (cal(high) - cal(low) + valid(low) + mod) % mod;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "1"\n"11"\n
// @lcpr case=end

// @lcpr case=start
// "90"\n"101"\n
// @lcpr case=end

 */

