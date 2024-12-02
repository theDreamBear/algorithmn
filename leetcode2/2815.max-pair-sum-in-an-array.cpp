/*
 * @lc app=leetcode.cn id=2815 lang=cpp
 * @lcpr version=30204
 *
 * [2815] 数组中的最大数对和
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
    int maxSum1(vector<int>& nums) {
        // 枚举右维护左
        map<int, int> mv;
        int ans = -1;
        for (auto v: nums) {
            int value = v;
            int ma = 0;
            while (v) {
                int x = v % 10; v /= 10;
                ma = max(ma, x);
            }
            if (mv.count(ma)) {
                ans = max(ans, value + mv[ma]);
            }
            mv[ma] = max(mv[ma], value);
        }
        return ans;
    }

    int maxSum(vector<int>& nums) {
        // 枚举右维护左
        vector<int> mv(10, INT_MIN);
        int ans = -1;
        for (auto v: nums) {
            int ma = 0;
            for (int x = v; x; x /= 10) {
                ma = max(ma, x%10);
            }
            if (mv[ma] != INT_MIN) {
                ans = max(ans, v + mv[ma]);
            }
            mv[ma] = max(mv[ma], v);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [51,71,17,24,42]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

