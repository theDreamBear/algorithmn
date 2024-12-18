/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 * @lcpr version=30204
 *
 * [2522] 将字符串分割成值不超过 K 的子字符串
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
    int minimumPartition1(string s, int k) {
        int n = s.size();
        const int inf = INT_MAX / 2;
        vector<int> dp(n + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            long long val = 0;
            for (int j = i; j <= n and val <= k; j++) {
                val = val * 10 + (s[j - 1] - '0');
                if (j == i and val > k) {
                    return -1;
                }
                if (val <= k) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
            }
        }
        return dp[n];
    }

    // 贪心, 前面的尽可能长
    int minimumPartition(string s, int k) {
        int n = s.size();
        int ans = 1;
        long long val = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - '0';
            if (c > k) return -1;
            val = val * 10 + c;
            if (val > k) {
                ans++;
                val = c;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "165462"\n60\n
// @lcpr case=end

// @lcpr case=start
// "238182"\n5\n
// @lcpr case=end

 */

