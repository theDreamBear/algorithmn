/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 * @lcpr version=30121
 *
 * [2266] 统计打字方案数
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

const static int MOD = 1e9 + 7, MX = 1e5 + 1;
int f[MX], g[MX];

class Solution {
public:
    int countTexts1(string pressedKeys) {
        vector<int> dp(pressedKeys.size() + 1);
        dp[0] = 1;
        for (int i = 0; i < pressedKeys.size(); i++) {
            dp[i + 1] = dp[i];
            int t = (pressedKeys[i] == '7' or pressedKeys[i] == '9') ? 4 : 3;
            for (int j = 1; j < t and i - j >= 0 and pressedKeys[i] == pressedKeys[i - j]; j++) {
                dp[i + 1] = (dp[i + 1] +  dp[i - j]) % (int)(1e9 + 7);
            }
        }
        return dp.back();
    }



    int countTexts(string pressedKeys) {
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;
        for (int i = 4; i < pressedKeys.size() + 1; i++) {
            f[i] = ((long long)f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = ((long long)g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }
        int ans = 1;
        int cnt = 0;
        char alpha;
        for (auto ch : pressedKeys) {
            if (cnt == 0) {
                cnt = 1;
                alpha = ch;
            } else {
                if (ch == alpha) {
                    ++cnt;
                } else {
                    ans = (long long)ans * ((alpha == '7' or alpha == '9') ? g[cnt] : f[cnt]) % MOD;
                    cnt = 1;
                    alpha = ch;
                }
            }
        }
        ans = (long long)ans * ((alpha == '7' or alpha == '9') ? g[cnt] : f[cnt]) % MOD;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "22233"\n
// @lcpr case=end

// @lcpr case=start
// "222222222222222222222222222222222222"\n
// @lcpr case=end

 */

