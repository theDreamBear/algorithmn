/*
 * @lc app=leetcode.cn id=668 lang=cpp
 * @lcpr version=30204
 *
 * [668] 乘法表中第k小的数
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
    int findKthNumber(int m, int n, int k) {
        auto can = [&](long long val) {
            int cnt = 0;
            for (int i = 1; i <= m; i++) {
                cnt += min(val / i, (long long)n);
                if (cnt >= k) {
                    return true;
                }
            }
            return false;
        };
        // 枚举数字
        long long low = 1, high = (long long)m * n;
        while (low + 1 < high) {
            auto mid = low + (high - low) / 2;
            if (can(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (can(low)) return low;
        return high;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n3\n5\n
// @lcpr case=end

// @lcpr case=start
// 2\n3\n6\n
// @lcpr case=end

 */

