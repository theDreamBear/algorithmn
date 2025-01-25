/*
 * @lc app=leetcode.cn id=3413 lang=cpp
 * @lcpr version=30204
 *
 * [3413] 收集连续 K 个袋子可以获得的最多硬币数量
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    long long maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        long long ans = 0;
        for (long long i = 0, left = 0, right = 0, sum = 0, rsum = 0, lsum = 0; i < tiles.size(); i++) {
            long long l = tiles[i][0], r = tiles[i][1], c = tiles[i][2];
            // // l为左端点
            while (right < tiles.size() and tiles[right][1] < l + carpetLen - 1) {
                rsum += (long long)(tiles[right][1] - tiles[right][0] + 1) * tiles[right][2];
                right++;
            }
            long long rv = rsum - sum;
            if (right < tiles.size()) {
                rv += max(0ll, (long long)(l + carpetLen - 1 - tiles[right][0] + 1) * tiles[right][2]);
            }
            ans = max(ans, rv);
            sum += (r - l + 1) * c;

            // 解法二 右端点
            // r 为右端点
            // while (left < i and tiles[left][1] < r - carpetLen + 1) {
            //     lsum += (tiles[left][1] - tiles[left][0] + 1);
            //     left++;
            // }
            // long long lv = sum - lsum;
            // if (left < i) {
            //     lv -= max(r - carpetLen + 1 - tiles[left][0], 0);
            // }
            // ans = max(ans, lv);
        }
        return ans;
    }

    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long ans = 0;
        sort(coins.begin(), coins.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });
        ans = max(ans, maximumWhiteTiles(coins, k));
        ranges::reverse(coins);
        for (auto& vec: coins) {
            int tmp = -vec[0];
            vec[0] = -vec[1];
            vec[1] = tmp;
        }
        ans = max(ans, maximumWhiteTiles(coins, k));
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[8,10,1],[1,3,2],[5,6,4]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,10,3]]\n2\n
// @lcpr case=end

 */

