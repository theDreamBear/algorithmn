/*
 * @lc app=leetcode.cn id=2857 lang=cpp
 * @lcpr version=30204
 *
 * [2857] 统计距离为 k 的点对
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 超时
    int countPairs_tle(vector<vector<int>>& coordinates, int k) {
        // 按照横坐标排序
        int ans = 0;
        ranges::sort(coordinates, {}, [](auto& a) {return a[0];});
        for (int i = 1; i < coordinates.size(); i++) {
            // 错误(coordinates[i][0] ^ coordinates[j][0]) <= k
            //  因为不是单调的
            // 但是想对单调
            for (int j = i - 1; j >= 0 and (coordinates[i][0] ^ coordinates[j][0]) <= k + 64; j--) {
                if ((coordinates[i][0] ^ coordinates[j][0]) + (coordinates[i][1] ^ coordinates[j][1]) == k) {
                    ans++;
                }
            }
        }
        return ans;
    }

    // count
    int countPairs1(vector<vector<int>>& coordinates, int k) {
        // 按照横坐标排序
        long long ans = 0;
        // 注意到k 的范围很小
        map<pair<int, int>, int> cnt;
        for (auto& vec: coordinates) {
            cnt[{vec[0], vec[1]}]++;
        }
        // 枚举x
        for (int x = 0; x <= 100; x++) {
            for (int i = 0; i < coordinates.size(); i++) {
                int x2 = coordinates[i][0] ^ x;
                int y2 = (k - x) ^ coordinates[i][1];
                if (!cnt.count({x2, y2})) continue;
                long long z = cnt[{x2, y2}];
                if (coordinates[i][0] == x2 and coordinates[i][1] == y2) {
                    ans += (z * (z - 1));
                    cnt.erase({x2, y2});
                } else {
                    ans += z;
                }
            }
        }
        return ans / 2;
    }

    int countPairs2(vector<vector<int>>& coordinates, int k) {
        // 按照横坐标排序
        long long ans = 0;
        auto getHash = [&](long long x, long long y) {
            return x << 32 | y;
        };
        // 注意到k 的范围很小
        map<long long, int> cnt;
        for (auto& vec: coordinates) {
            cnt[getHash(vec[0], vec[1])]++;
        }
        // 枚举x
        for (int x = 0; x <= 100; x++) {
            for (int i = 0; i < coordinates.size(); i++) {
                int x2 = coordinates[i][0] ^ x;
                int y2 = (k - x) ^ coordinates[i][1];
                auto code = getHash(x2, y2);
                if (!cnt.count(code)) continue;
                long long z = cnt[code];
                if (coordinates[i][0] == x2 and coordinates[i][1] == y2) {
                    ans += (z * (z - 1));
                    cnt.erase(code);
                } else {
                    ans += z;
                }
            }
        }
        return ans / 2;
    }

    // 枚举右, 维护左
    int countPairs(vector<vector<int>>& coordinates, int k) {
        // 按照横坐标排序
        int ans = 0;
        auto getHash = [&](long long x, long long y) {
            return x << 32 | y;
        };
        // 注意到k 的范围很小
        map<long long, int> cnt;
        // 枚举x
        for (auto& p: coordinates) {
            int x1 = p[0], y1 = p[1];
            for (int x = 0; x <= k; x++) {
                int x2 = x1 ^ x;
                int y2 = (k - x) ^ y1;
                auto code = getHash(x2, y2);
                if (cnt.count(code)) ans += cnt[code];
            }
            cnt[getHash(x1, y1)]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2],[4,2],[1,3],[5,2]]\n5\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[1,3],[1,3],[1,3],[1,3]]\n0\n
// @lcpr case=end

 */

