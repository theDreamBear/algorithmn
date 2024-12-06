/*
 * @lc app=leetcode.cn id=3296 lang=cpp
 * @lcpr version=30204
 *
 * [3296] 移山所需的最少秒数
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
    // 一次二分
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e17;
        auto can = [&](long long m) {
            long long ans = 0;
            for (auto a: workerTimes) {
                auto x = (-1 + sqrt(1 + 8ll * m / a)) / 2;
                ans += x;
                if (ans >= mountainHeight) return true;
            }
            return false;
        };
        while (low + 1 < high) {
            auto mid = (low + high) >> 1;
            if (can(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (can(low)) {
            return low;
        }
        return high;
    }

    // 两次二分
    long long minNumberOfSeconds2(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0, high = 1e17;

        auto can = [&](long long mid) {
            long long ans = 0;
            for (auto a: workerTimes) {
                long long l = 0, h = 1e5;
                while (l + 1 < h) {
                    auto m = (l + h) >> 1;
                    if (m * (m + 1) * a / 2 <= mid) {
                        l = m;
                    } else {
                        h = m;
                    }
                }
                if (h * (h + 1) * a / 2 <= mid)  {
                    ans += h;
                } else {
                    ans += l;
                }
                if (ans >= mountainHeight) return true;
            }
            return false;
        };
        while (low + 1 < high) {
            auto mid = (low + high) >> 1;
            if (can(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (can(low)) {
            return low;
        }
        return high;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n[2,1,1]\n
// @lcpr case=end

// @lcpr case=start
// 10\n[3,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[1]\n
// @lcpr case=end

 */

