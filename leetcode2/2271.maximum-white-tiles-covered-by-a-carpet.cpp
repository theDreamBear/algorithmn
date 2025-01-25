/*
 * @lc app=leetcode.cn id=2271 lang=cpp
 * @lcpr version=30204
 *
 * [2271] 毯子覆盖的最多白色砖块数
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
    // 二分搜索
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0;
        sort(tiles.begin(), tiles.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });
        int n = tiles.size();
        vector<long long> presum(n + 1);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + tiles[i][1] - tiles[i][0] + 1;
        }
        for (int i = 0; i < tiles.size(); i++) {
            int l = tiles[i][0], r = tiles[i][1];
            if (r - l + 1 >= carpetLen) {
                return carpetLen;
            }
            // 左端点为 l
            // auto it = lower_bound(tiles.begin() + i, tiles.end(), l + carpetLen - 1, [](auto& x, int v) {
            //     return x[1] < v;
            // });
            // if (it != tiles.begin()) {
            //     --it;
            //     int j = it - tiles.begin();
            //     int mid = r - l + 1 + presum[j + 1] - presum[i + 1];
            //     // j 不是最后一个
            //     if (j + 1 < tiles.size()) {
            //         mid += max(0, l + carpetLen - 1 - tiles[j + 1][0] + 1);
            //     }
            //     ans = max(ans, mid);
            // }

            // 右端点为 r
            auto it = lower_bound(tiles.begin(), tiles.begin() + i + 1, r - carpetLen + 1, [](auto& x, int v) {
                return x[1] < v;
            });
            int j = it - tiles.begin();
            int mid = r - l + 1;
            if (i != j) {
                mid += tiles[j][1] - max(tiles[j][0], r - carpetLen + 1) + 1 + presum[i] - presum[j + 1];
            }
            ans = max(ans, mid);

        }
        return ans;
    }

     // 注意到二分是单调的, 所以可以用双指针优化
    int maximumWhiteTiles1(vector<vector<int>>& tiles, int carpetLen) {
        int ans = 0;
        sort(tiles.begin(), tiles.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });
        int n = tiles.size();
        for (long long i = 0, left = 0, right = 0, sum = 0, rsum = 0, lsum = 0; i < tiles.size(); i++) {
            int l = tiles[i][0], r = tiles[i][1];
            if (r - l + 1 >= carpetLen) {
                return carpetLen;
            }
            // // l为左端点
            while (right < tiles.size() and tiles[right][1] < l + carpetLen - 1) {
                rsum += (tiles[right][1] - tiles[right][0] + 1);
                right++;
            }
            int rv = rsum - sum;
            if (right < tiles.size()) {
                rv += max(0, l + carpetLen - 1 - tiles[right][0] + 1);
            }
            ans = max(ans, rv);
            sum += r - l + 1;

            // 解法二 右端点
            // r 为右端点
            // while (left < i and tiles[left][1] < r - carpetLen + 1) {
            //     lsum += (tiles[left][1] - tiles[left][0] + 1);
            //     left++;
            // }
            // int lv = sum - lsum;
            // if (left < i) {
            //     lv -= max(r - carpetLen + 1 - tiles[left][0], 0);
            // }
            // ans = max(ans, lv);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,5],[10,11],[12,18],[20,25],[30,32]]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[10,11],[1,1]]\n2\n
// @lcpr case=end

 */

