/*
 * @lc app=leetcode.cn id=740 lang=cpp
 * @lcpr version=30122
 *
 * [740] 删除并获得点数
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
    int deleteAndEarn1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> value;
        for (auto v : nums) {
            value[v] += v;
        }
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        vector<int> dp(nums.size());
        dp[0] = value[nums[0]];
        if (nums.size() == 1) {
            return dp[0];
        }
        if (nums[1] == nums[0] + 1) {
            dp[1] = max(dp[0], value[nums[1]]);
        } else {
            dp[1] = dp[0] + value[nums[1]];
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                dp[i] = max(dp[i - 1], dp[i - 2] + value[nums[i]]);
            } else {
                dp[i] = dp[i - 1] + value[nums[i]];
            }
        }
        return dp.back();
    }

    int rob(const vector<int>& data) {
        if (data.size() == 1) {
            return data.front();
        }
        int prepre = data[0], pre = max(prepre, data[1]);
        for (int i = 2; i < data.size(); i++) {
            int v = max(pre, prepre + data[i]);
            prepre = pre;
            pre = v;
        }
        return pre;
    }

    int deleteAndEarn_space(vector<int>& nums) {
        // 空间换时间
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> data(max_val + 1);
        for (auto v : nums) {
            data[v] += v;
        }
        return rob(data);
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> data = {nums[0]};
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            int v = nums[i];
            if (v == nums[i - 1]) {
                data.back() += v;
            } else if (v == nums[i - 1] + 1) {
                data.push_back(v);
            } else {
                ans += rob(data);
                data = {v};
            }
        }
        ans += rob(data);
        return ans;
    }
    

};
// @lc code=end



/*
// @lcpr case=start
// [3,4,2]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3,3,4]\n
// @lcpr case=end

 */

