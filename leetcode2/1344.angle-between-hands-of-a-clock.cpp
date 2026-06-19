/*
 * @lc app=leetcode.cn id=1344 lang=cpp
 * @lcpr version=30204
 *
 * [1344] 时钟指针的夹角
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
    double angleClock(int hour, int minutes) {
        hour %= 12;
        auto x1 = (hour * 60 + minutes) / 720.0 * 360;
        auto x2 = minutes * 6;
        return min(abs(x1 - x2), 360 - abs(x1 - x2));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n30\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n15\n
// @lcpr case=end

// @lcpr case=start
// 4\n50\n
// @lcpr case=end

// @lcpr case=start
// 12\n0\n
// @lcpr case=end

 */

