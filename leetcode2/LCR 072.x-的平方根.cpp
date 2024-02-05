/*
 * @lc app=leetcode.cn id=LCR 072 lang=cpp
 * @lcpr version=30115
 *
 * [LCR 072] x 的平方根
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
    int mySqrt(int x) {
        long long low = 0, high = x;
        while (low + 1 < high) {
            auto mid = (high - low) / 2 + low;
            if (mid * mid > x) {
                high = mid;
            } else {
                low = mid;
            }
        }
        if (high * high <= x) {
            return high;
        }
        return low;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

