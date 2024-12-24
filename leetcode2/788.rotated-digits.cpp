/*
 * @lc app=leetcode.cn id=788 lang=cpp
 * @lcpr version=30204
 *
 * [788] 旋转数字
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
    // 看清楚题目啊, 明明不难, 妹的浪费时间
    // 相同 0 1 8
    // 互转2 <-> 5, 6 <-> 9
    int rotatedDigits(int n) {
        string highNum = to_string(n);
        string lowNum = string(highNum.size(), '0');
        int dp[2][2][2][10];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int m = 0; m < 2; m++) {
                    for (int k = 0; k < 10; k++) {
                        dp[i][j][m][k] = -1;
                    }
                }
            }
        }
        // isLow isHigh
        //  0     0      0-9
        //  0     1      0-s2
        //  1     0      s1-9
        //  1     1      s1-s2
        int cnt[10]{};
        cnt[0] = cnt[1] = cnt[8] = cnt[2] = cnt[5] = cnt[6] = cnt[9] = 1;
        int same[10]{};
        same[0] = same[1] = same[8] = 1;
        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int isSame, int pos)->int {
            if (pos >= lowNum.size()) {
                return !isSame;
            }
            if (dp[isLow][isHigh][isSame][pos] != -1) {
                return dp[isLow][isHigh][isSame][pos];
            }
            auto low = lowNum[pos], high = highNum[pos];
            if (!isLow) {
                low = '0';
                if (!isHigh) {
                    high = '9';
                }
            } else {
                if (!isHigh) {
                    high = '9';
                }
            }
            int ans = 0;
            int cnt2[10]{};
            for (auto x = low; x <= high; x++) {
                if (cnt[x - '0']) {
                    ans += dfs(dfs, isLow and x == lowNum[pos], isHigh and x == highNum[pos], isSame and same[x - '0'], pos + 1);
                }
            }
            return dp[isLow][isHigh][isSame][pos] = ans;
        };
        return dfs(dfs, 1, 1, 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

 */

