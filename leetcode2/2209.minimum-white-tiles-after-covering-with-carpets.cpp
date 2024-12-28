/*
 * @lc app=leetcode.cn id=2209 lang=cpp
 * @lcpr version=30204
 *
 * [2209] 用地毯覆盖后的最少白色砖块
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
    int minimumWhiteTiles1(string floor, int numCarpets, int carpetLen) {
        // f[i][left]
        // 以i结尾的
        int n = floor.size();
        vector<int> cnt(n + carpetLen + 1);
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] = cnt[i - 1] + (i - 1 < n and floor[i - 1] == '1');
        }
        int dp[1010][1010]{};
        memset(dp, -1, sizeof dp);
        auto dfs = [&](auto& dfs, int i, int left) {
            if (i >= n or left == 0) return 0;
            auto& ans = dp[i][left];
            if (ans != -1) return ans;
            // 从下一个地方开始铺设
            ans = dfs(dfs, i + 1, left);
            // 从i开始铺设                                      // 覆盖的白色个数
            ans = max(ans, dfs(dfs, i + carpetLen, left - 1) + cnt[i + carpetLen] - cnt[i]);
            return ans;
        };
        return ranges::count(floor, '1') - dfs(dfs, 0, numCarpets);
    }

    int minimumWhiteTiles2(string floor, int numCarpets, int carpetLen) {
        // f[i][left]
        // 以i结尾的
        int n = floor.size();
        vector<int> cnt(n + carpetLen + 1);
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] = cnt[i - 1] + (i - 1 < n and floor[i - 1] == '1');
        }
        int dp[2010][1010]{};
        for (int i = n - 1; i >= 0; i--) {
            for (int left = 0; left <= numCarpets; left++) {
                dp[i][left] = dp[i + 1][left];
                if (left > 0) {
                    dp[i][left] = max(dp[i][left], dp[i + carpetLen][left - 1] + cnt[i + carpetLen] - cnt[i]);
                }
            }
        }
        return ranges::count(floor, '1') - dp[0][numCarpets];
    }

    int minimumWhiteTiles3(string floor, int numCarpets, int carpetLen) {
        // f[i][left]
        // 以i结尾的
        int n = floor.size();
        int dp[2010][1010]{};
        for (int i = n - 1; i >= 0; i--) {
            for (int left = 0; left <= numCarpets; left++) {
                dp[i][left] = dp[i + 1][left] + (floor[i] == '1');
                if (left > 0) {
                    dp[i][left] = min(dp[i][left], dp[i + carpetLen][left - 1]);
                }
            }
        }
        return dp[0][numCarpets];
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        // f[i][left]
        // 以i结尾的
        int n = floor.size();
        int dp[2][2010]{};
        // f[left][j] = f[left][j + 1] + floor[j] == '1';
        //            = f[left - 1][j + carpetLen];
        int ft = 0, st = 1;
        for (int left = 0; left <= numCarpets; left++) {
            for (int j = n - 1; j >= 0; j--) {
                dp[st][j] = dp[st][j + 1] + (floor[j] == '1');
                if (left > 0) {
                    dp[st][j] = min(dp[st][j], dp[ft][j + carpetLen]);
                }
            }
            swap(ft, st);
        }
        return dp[ft][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "10110101"\n2\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n2\n3\n
// @lcpr case=end

 */

