/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30204
 *
 * [410] 分割数组的最大值
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
    int splitArray(vector<int>& nums, int k) {
        // 枚举这个最小值
        auto can = [&](int val) {
            int cnt = 0;
            int sum = 0;
            for (auto x: nums) {
                if (sum + x <= val) {
                    sum += x;
                } else {
                    cnt++;
                    sum = x;
                }
            }
            // 最后一段需要加入统计
            return cnt + 1 <= k;
        };
        int low = ranges::max(nums), high = 1e9;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
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
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */

