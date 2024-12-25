/*
 * @lc app=leetcode.cn id=2827 lang=cpp
 * @lcpr version=30204
 *
 * [2827] 范围中美丽整数的数目
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
    // 对于针对 isnum == 0 有情况需要判断的, 使用v1 更加合适
    // isnum 处理的不优雅
    int numberOfBeautifulIntegers_v2(int low, int high, int k) {
        string s = to_string(high);
        string t = to_string(low);
        string oldt = t;
        int diff = s.size() - t.size();
        if (t.size() < s.size()) {
            t = string(s.size() - t.size(), '0') + t;
        }
        int ans = 0;
        int dp[2][2][40][20][20];
        memset(dp, -1, sizeof(int) * 2 * 2 * 40 * 20 * 20);

        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int cnt, int left, int pos)->int {
            if (pos >= s.size()) {
                return left % k == 0 and cnt == 0;
            }
            auto& ans = dp[isLow][isHigh][cnt + 20][left][pos];
            if (ans != -1) {
                return ans;
            }
            int high = isHigh ? s[pos] - '0' : 9;
            int low = isLow ? t[pos] - '0' : 0;
            ans = 0;
            for (auto x = low; x <= high; x++)
            {
                // isNum
                int ncnt = cnt;
                if (pos < diff and isLow and x == 0) {

                } else {
                    ncnt = cnt + (x % 2 == 0 ? 1 : -1);
                }
                ans += dfs(dfs, isLow and x + '0' == t[pos], isHigh and x + '0' == s[pos], ncnt, (left * 10 + x) % k, pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0, 0, 0);
    }

    int cal(int high, int k) {
        string s = to_string(high);
        int dp[2][2][40][20][20];
        memset(dp, -1, sizeof(int) * 2 * 2 * 40 * 20 * 20);

        auto dfs = [&](auto&& dfs, int isNum, int isHigh, int cnt, int left, int pos)->int {
            if (pos >= s.size()) {
                return left % k == 0 and cnt == 0 and isNum;
            }
            auto& ans = dp[isNum][isHigh][cnt + 20][left][pos];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            // 跳过
            if (!isNum) {
                ans = dfs(dfs, 0, 0, 0, 0, pos + 1);
            }
            int low = isNum ? 0 : 1;
            int high = isHigh ? s[pos] - '0' : 9;
            for (auto x = low; x <= high; x++) {
                ans += dfs(dfs, 1, isHigh and x + '0' == s[pos], cnt + (x % 2 == 0 ? 1 : -1), (left * 10 + x) % k, pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 0, 1, 0, 0, 0);
    }

    // 使用v1代码更好理解
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return cal(high, k) - cal(low - 1, k);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n20\n3\n
// @lcpr case=end

// @lcpr case=start
// 1\n10\n1\n
// @lcpr case=end

// @lcpr case=start
// 5\n5\n2\n
// @lcpr case=end

 */

