/*
 * @lc app=leetcode.cn id=638 lang=cpp
 * @lcpr version=30204
 *
 * [638] 大礼包
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
#include <map>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 超时
    int shoppingOffers_tle(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<vector<int>> arr = special;
        int n = price.size();
        for (int i = 0 ; i < n; i++) {
            vector<int> tmp(n + 1);
            tmp[i] = 1;
            tmp[n] = price[i];
            arr.push_back(tmp);
        }
        map<array<int, 7>, long long> dp;
        auto dfs = [&](auto&& dfs, array<int, 7>& cur)->long long {
            if (cur[6] < 0) {
                for (int i = 0; i < 6; i++) {
                    if (cur[i] != 0) {
                        return LLONG_MAX / 2;
                    }
                }
                return 0;
            }
            if (dp.contains(cur)) {
                return dp[cur];
            }
            // 选或者不选
            // 选择
            long long ans = LLONG_MAX / 2;
            // 不取
            cur[6]--;
            ans = min(ans, dfs(dfs, cur));
            cur[6]++;
            int pos = cur[6];
            auto old = cur;
            // 取几次
            int t = 0;
            cur[6]--;
            while (true) {
                bool ok = true;
                for (int i = 0; i < arr[pos].size() - 1; i++) {
                    cur[i] -= arr[pos][i];
                    if (cur[i] < 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    t++;
                    ans = min(ans, arr[pos].back() * t + dfs(dfs, cur));
                } else {
                    cur = old;
                    break;
                }
            }
            return dp[cur] = ans;
        };
        array<int, 7> cur{};
        for (int i = 0; i < n; i++) {
            cur[i] = needs[i];
        }
        cur[6] = arr.size() - 1;
        return dfs(dfs, cur);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,5]\n[[3,0,5],[1,2,10]]\n[3,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n[[1,1,0,4],[2,2,1,9]]\n[1,2,1]\n
// @lcpr case=end

 */

