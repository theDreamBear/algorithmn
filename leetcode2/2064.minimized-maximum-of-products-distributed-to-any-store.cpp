/*
 * @lc app=leetcode.cn id=2064 lang=cpp
 * @lcpr version=30204
 *
 * [2064] 分配给商店的最多商品的最小值
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
    int minimizedMaximum1(int n, vector<int>& quantities) {
        auto check = [&](int val) {
            // j 当前分配的下标
            // s 当前下标以分配数
            // i 当前商店下标
            int j = 0, s = 0, i = 0;
            for (; i < n and j < quantities.size(); i++) {
                // 当前商品数量可以分配完毕
                if (quantities[j] - s <= val) {
                    s = 0;
                    j++;
                } else {
                    // 当前商品过剩
                    s += val;
                }
            }
            // 能够分完毕, 多余的商店分0就行了
            return j >= quantities.size();
        };
        int low = 0, high = ranges::max(quantities);
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (check(low)) return low;
        return high;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        auto check = [&](int val) {
            int cnt = 0;
            for (auto q: quantities) {
                cnt += (q + val - 1) / val;
            }
            return cnt <= n;
        };
        // (]
        int low = 0, high = ranges::max(quantities);
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (check(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        //if (check(low)) return low;
        return high;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n[11,6]\n
// @lcpr case=end

// @lcpr case=start
// 7\n[15,10,10]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[100000]\n
// @lcpr case=end

 */

