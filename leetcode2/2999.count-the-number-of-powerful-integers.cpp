/*
 * @lc app=leetcode.cn id=2999 lang=cpp
 * @lcpr version=30204
 *
 * [2999] 统计强大整数的数目
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
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st = to_string(start), et = to_string(finish);
        if (st.size() < et.size()) {
            st = string(et.size() - st.size(), '0') + st;
        }
        auto isIn = [&](int pos) {
            return s.size() - et.size() + pos;
        };
        long long dp[2][2][20];
        memset(dp, -1, sizeof(long long) * 2 * 2 * 20);

        auto dfs = [&](auto&& dfs, int isLow, int isHigh, int pos)->long long {
            if (pos >= et.size()) {
                return 1;
            }
            auto& ans = dp[isLow][isHigh][pos];
            if (ans != -1) {
                return ans;
            }
            ans = 0;
            int low = isLow ? st[pos] - '0': 0;
            int high = isHigh ? et[pos] - '0': limit;
            int p = isIn(pos);
            if (p >= 0) {
                if (isHigh and s[p] > et[pos]) {
                    return ans;
                }
                if (isLow and s[p] < st[pos]) {
                    return ans;
                }
                low = s[p] - '0';
                high = low;
            }
            for (auto x = low; x <= min(high, limit); x++) {
                ans += dfs(dfs, isLow and x + '0' == st[pos], isHigh and x + '0' == et[pos], pos + 1);
            }
            return ans;
        };
        return dfs(dfs, 1, 1, 0);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n6000\n4\n"124"\n
// @lcpr case=end

// @lcpr case=start
// 15\n215\n6\n"10"\n
// @lcpr case=end

// @lcpr case=start
// 1000\n2000\n4\n"3000"\n
// @lcpr case=end

 */

