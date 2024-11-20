/*
 * @lc app=leetcode.cn id=1866 lang=cpp
 * @lcpr version=30204
 *
 * [1866] 恰有 K 根木棍可以看到的排列数目
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
    int rearrangeSticks(int n, int k) {
        // s(n, k) s[0]][0] = 1, s[k][0] = 0
        long long s[n + 1][k + 1];
        s[0][0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                s[i][j] = 0;
            }
            s[i][0] = 0;
            if (i <= k) {
                s[i][i] = 1;
            }
        }
        int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i - 1, k); j++) {
                s[i][j] = (s[i - 1][j - 1] + (i - 1) * s[i - 1][j]) % mod;
            }
        }
        return s[n][k];
    }
};
// @lc code=end




/*
// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 5\n5\n
// @lcpr case=end

// @lcpr case=start
// 20\n11\n
// @lcpr case=end

 */

