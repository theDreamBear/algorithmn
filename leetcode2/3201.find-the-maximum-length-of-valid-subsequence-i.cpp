/*
 * @lc app=leetcode.cn id=3201 lang=cpp
 * @lcpr version=30204
 *
 * [3201] 找出有效子序列的最大长度 I
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
    int maximumLength(vector<int>& nums) {
        // 都是奇数
        // 都是偶数
        // 奇数开头, or 偶数开头
        int odd = 0, even = 0;
        for (auto& v: nums) {
            if (v % 2 == 1) {
                odd++;
            } else {
                even++;
            }
        }
        int ans = 1, v = nums[0] % 2;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 != v) {
                ans++;
                v = !v;
            }
        }
        return max({odd, even, ans});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,1,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

