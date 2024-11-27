/*
 * @lc app=leetcode.cn id=3208 lang=cpp
 * @lcpr version=30204
 *
 * [3208] 交替组 II
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
    int numberOfAlternatingGroups1(vector<int> &colors, int k) {
        int n = colors.size();
        int ans = 0;
        vector<int> dp(n, 0);
        // dp[i] 表示以第i个元素结尾的最长交替子序列的长度
        int i = n - 1, len = 1;
        while (i != 0 and colors[i] != colors[((i + 1) + n) % n]) {
            i = (i - 1 + n) % n;
            len++;
        }
        ans = len >= k ? 1 : 0;
        dp[0] = len;
        for (int i = 1; i < n; i++) {
            if (colors[i] != colors[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                if (dp[i] >= k) {
                    ans++;
                }
            } else {
                dp[i] = 1;
            }
        }
        return ans;
    }

    // 化圆为线
    int numberOfAlternatingGroups(vector<int> &colors, int k) {
        int n = colors.size();
        int ans = 0, cnt = 0;
        for (int i = 0; i < n * 2; i++) {
            // 以i J结尾的最大长度
            if (i > 0 and colors[i % n] == colors[(i + n - 1) % n]) {
                cnt = 0;
            }
            ++cnt;
            ans += i >= n and cnt >= k;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,1,0]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1,0,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1]\n4\n
// @lcpr case=end

 */

