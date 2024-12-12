/*
 * @lc app=leetcode.cn id=2712 lang=cpp
 * @lcpr version=30204
 *
 * [2712] 使所有字符相等的最小成本
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
    // 哈哈, 仔细想还是出来了
    long long minimumCost1(string s) {
        vector<int> pre{0};
        // 分组循环
        for (int i = 0; i < s.size(); ) {
            int start = i++;
            while (i < s.size() and s[start] == s[i]) i++;
            pre.push_back(pre.back() + i - start);
        }
        int n = pre.size();
        vector<long long> preSum(n);
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + pre[i];
        }

        vector<long long> suf{0};
        // 分组循环
        for (int i = s.size() - 1; i >= 0; ) {
            int start = i--;
            while (i >= 0 and s[start] == s[i]) i--;
            suf.push_back(suf.back() + start - i);
        }
        //int n = pre.size();
        vector<long long> sufSum(n);
        for (int i = 1; i < n; i++) {
            sufSum[i] = sufSum[i - 1] + suf[i];
        }
        //
        long long ans = n >= 2 ? min(sufSum[n - 2], preSum[n - 2]) : 0;
        for (int i = 1; i + 1 < preSum.size(); i++) {
            //char ch = s[pre[i] - 1];
            ans = min({ans, preSum[i - 1] + sufSum[n - i - 1], preSum[i] + sufSum[n - i - 2]});
        }
        return ans == LLONG_MAX ? 0: ans;
    }

    long long minimumCost(string s) {
        // 正常dp
        int n = s.size();
        long long f[n + 2][2], g[n + 2][2];
        f[0][0] = f[0][1] = 0;
        
        for (int i = 1, last = 1; i <= n; i++) {
            if (s[i - 1] != s[last - 1]) last = i;
            for (int j = 0; j < 2; j++) {
                f[i][j] = (s[i - 1] == '0' + j) ? f[last - 1][j] : f[last - 1][j ^ 1] + i;
            }
        }

        g[n + 1][0] = g[n + 1][1] = 0;
        
        for (int i = n, last = n; i >= 1; i--) {
            if (s[i - 1] != s[last - 1]) last = i;
            for (int j = 0; j < 2; j++) {
                g[i][j] = (s[i - 1] == '0' + j) ? g[last + 1][j] : g[last + 1][j ^ 1] + n - i + 1;
            }
        }
        long long ans = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            ans = min({ans, f[i][0] + g[i + 1][0], f[i][1] + g[i + 1][1]});
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0011"\n
// @lcpr case=end

// @lcpr case=start
// "010101"\n
// @lcpr case=end

 */

