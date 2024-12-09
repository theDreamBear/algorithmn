/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 * @lcpr version=30204
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
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
    // 枚举子数组的左区间
    long long countSubarrays(vector<int>& nums, int k) {
        int ma = ranges::max(nums);
        int ct = 0, n = nums.size();
        long long ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            if (nums[right] == ma) ++ct;
            while (ct >= k) {
                ans += (n - right);
                if (nums[left++] == ma) {
                    ct--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,2,1]\n3\n
// @lcpr case=end

 */

