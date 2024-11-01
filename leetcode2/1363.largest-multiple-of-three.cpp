/*
 * @lc app=leetcode.cn id=1363 lang=cpp
 * @lcpr version=30204
 *
 * [1363] 形成三的最大倍数
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
#include <bits/stdc++.h>
using namespace std;
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // MLE, 需要先构造长度, 根据dp构造答案
    string largestMultipleOfThree1(vector<int>& digits) {
        ranges::sort(digits, greater<>{});
        // 0, 1, 2
        string dp[2][3];
        auto cmp = [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() > b.size();
            }
            return a > b;
        };
        auto get_max = [&](const string& a, const string& b) {
            if (cmp(a, b)) {
                return a;
            }
            return b;
        };
        int ft = 0, st = 1;
        string tmp;
        for (auto v: digits) {
            int idx = v % 3;
            dp[st][0] = get_max(get_max(dp[ft][0], dp[ft][(3 - idx) % 3].size() ? (tmp = dp[ft][(3 - idx) % 3], tmp.push_back(v + '0'), tmp) : ""),  idx == 0 ? to_string(v): "");
            dp[st][1] = get_max(get_max(dp[ft][1], dp[ft][(4 - idx) % 3].size() ? (tmp = dp[ft][(4 - idx) % 3], tmp.push_back(v + '0'), tmp) : ""),  idx == 1 ? to_string(v): "");
            dp[st][2] = get_max(get_max(dp[ft][2], dp[ft][2 - idx].size() ? (tmp = dp[ft][2 - idx], tmp.push_back(v + '0'), tmp) : ""),  idx == 2 ? to_string(v): "");
            swap(ft, st);
        }
        auto ans = dp[ft][0];
        if (ans.empty()) {
            return "";
        }
        const char* p = ans.c_str();
        while (*p == '0') p++;
        if (*p == 0) return "0";
        return p;
    }

    string largestMultipleOfThree2(vector<int>& digits) {
        // 小到大方便构造
        ranges::sort(digits);
        // 0, 1, 2 
        int n = digits.size();
        int dp[n + 1][3];
        dp[0][1] = dp[0][2] = INT_MIN;
        for (int i = 0; i < n; i++) {
            int v = digits[i];
            int idx = v % 3;
            // dp[i][0] = max({dp[i - 1][0], getV(dp[i - 1][(3 - idx) % 3]),  idx == 0 ? 1: 0});
            // dp[i][1] = max({dp[i - 1][1], getV(dp[i - 1][(4 - idx) % 3]),  idx == 1 ? 1 : 0});
            // dp[i][2] = max({dp[i - 1][2], getV(dp[i - 1][2 - idx]),  idx == 2 ? 1: 0});
            for (int j = 0; j < 3; j++) {
                dp[i + 1][j] = max(dp[i][j], dp[i][(j + idx) % 3] + 1);
            }
        }
        // make ans
        int maxsize = dp[n][0];
        if (maxsize == 0) return "0";
        // 构造
        // 从后往前构造
        string res;
        // 能选就一定选, 因为后面的更大
        for (int i = n, j = 0; i > 0; i--) {
            if (dp[i][j] == dp[i - 1][(j + digits[i - 1]) % 3] + 1) {
                res += to_string(digits[i - 1]);
                j = (j + digits[i - 1]) % 3;
            }
        }
        if (res[0] == '0') {
            return "0";
        }
        return res;
    }

    // 贪心
    string largestMultipleOfThree(vector<int>& digits) {
        int cnt[10]{}, sum = 0;
        for (auto v : digits) cnt[v]++, sum += v;
        auto del = [&](int m) {
            for (int i = m; i <= 9; i += 3) {
                if (cnt[i]) {
                    cnt[i]--;
                    return 1;
                }
            }
            return 0;
        };
        if (sum % 3 == 1) {
            if (!del(1)) {
                del(2); del(2);
            }
        }
        if (sum % 3 == 2) {
            if (!del(2)) {
                del(1); del(1);
            }
        }
        string ans;
        for (int i = 9; i >= 0; i--) while (cnt[i]--) ans += i + '0';
        if (ans.size() and ans[0] == '0') return "0";
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [8,1,9]\n
// @lcpr case=end

// @lcpr case=start
// [8,6,7,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0,0,0,0]\n
// @lcpr case=end

 */

