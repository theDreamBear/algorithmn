/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 * @lcpr version=30204
 *
 * [2537] 统计好子数组的数目
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
    // 滑动窗口
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int, int> cnt;
        int res = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            res += cnt[nums[right]]++;
            while (res >= k) {
                res -= (--cnt[nums[left++]]);
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [3,1,4,3,2,2,4]\n2\n
// @lcpr case=end

 */

