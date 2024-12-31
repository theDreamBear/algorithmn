/*
 * @lc app=leetcode.cn id=2652 lang=cpp
 * @lcpr version=30204
 *
 * [2652] 倍数求和
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
    int sumOfMultiples1(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 or i % 5 == 0 or i % 7 == 0) ans += i;
        }
        return ans;
    }

    // 容斥
    int sumOfMultiples2(int n) {
        auto cal = [&](int k) {
            return n / k * (n / k + 1) * k / 2;
        };
        return cal(3) + cal(5) + cal(7) + cal(3 * 5 * 7) - cal(15) - cal(35) - cal(21);
    }

    int sumOfMultiples(int n) {
        auto cal = [&](int k) {
            return n / k * (n / k + 1) * k / 2;
        };
        int ans = 0;
        // 更加通用
        int x[3]{3, 5, 7};
        for (int i = 1; i < (1 << 3); i++) {
            int sign = __builtin_popcount(i) % 2 == 0 ? -1 : 1;
            int k = 1;
            for (int j = 0; j < 3; j++) {
                if (i >> j & 1) k *= x[j];
            }
            ans += sign * cal(k);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

 */

