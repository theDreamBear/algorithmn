/*
 * @lc app=leetcode.cn id=673 lang=cpp
 * @lcpr version=30204
 *
 * [673] 最长递增子序列的个数
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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n), ct(n);
        f[0] = 1;
        ct[0] = 1;
        for (int i = 1; i < n; i++) {
            int len = 1, t = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (f[j] + 1 < len) {
                        continue;
                    } else if (f[j] + 1 == len) {
                        t+=ct[j];
                    } else {
                        t = ct[j];
                        len = f[j] + 1;
                    }
                }
            }
            f[i] = len;
            ct[i] = t;
        }
        int v = ranges::max(f);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == v) ans += ct[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,5,4,7]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n
// @lcpr case=end

 */

