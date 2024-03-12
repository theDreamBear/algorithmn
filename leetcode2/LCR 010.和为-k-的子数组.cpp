/*
 * @lc app=leetcode.cn id=LCR 010 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 010] 和为 K 的子数组
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
    int subarraySum_bad(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0, right = 0, sum = 0;
        // 滑动窗口存在负数， 导致滑动窗口算法可能不合适
        for (; right < nums.size(); right++) {
            sum += nums[right];
            while (left <= right and sum > k) {
                sum -= nums[left];
                ++left;
            }
            if (left <= right and sum == k) {
                ++ans;
            }
        }

        return ans;
    }

    int subarraySum_bad2(vector<int>& nums, int k) {
        int ans = 0;
        // 前缀和 不行， 因为负数导致了 前缀和失去了单调性
        int n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        return ans;
    }

    int subarraySum_暴力_超时(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                if ((sum += nums[j]) == k) {
                    ++ans;
                }
            }
        }
        return ans;
    }

    // 前缀和 +  hash
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        for (auto v : nums) {
            pre += v;
            if (mp.count(pre - k)) {
                ans += mp[pre - k];
            }
            mp[pre]++;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */

