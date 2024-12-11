/*
 * @lc app=leetcode.cn id=2799 lang=cpp
 * @lcpr version=30204
 *
 * [2799] 统计完全子数组的数目
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
    int countCompleteSubarrays1(vector<int>& nums) {
        int cnt[3000]{};
        int T = 0;
        for (auto v: nums) {
            if (++cnt[v] == 1) {
                T++;
            }
        }
        int cnt2[3000]{};
        int t = 0;
        int n = nums.size();
        // 右端点
        int ans = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            if (++cnt2[nums[right]] == 1) {
                t++;
            }
            while (t == T) {
                ans += (n - right);
                if (--cnt2[nums[left++]] == 0) {
                    --t;
                }
            }
        }
        return ans;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int cnt[3000]{};
        int T = 0;
        for (auto v: nums) {
            if (++cnt[v] == 1) {
                T++;
            }
        }
        int cnt2[3000]{};
        int t = 0;
        int n = nums.size();
        // 右端点
        int ans = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            if (++cnt2[nums[right]] == 1) {
                t++;
            }
            while (t == T) {
                if (--cnt2[nums[left++]] == 0) {
                    --t;
                }
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,1,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

