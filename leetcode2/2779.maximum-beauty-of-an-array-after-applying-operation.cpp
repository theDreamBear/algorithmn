/*
 * @lc app=leetcode.cn id=2779 lang=cpp
 * @lcpr version=30204
 *
 * [2779] 数组的最大美丽值
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
#include <map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumBeauty1(vector<int>& nums, int k) {
        //ranges::sort(nums);
        vector<int> arr(3e5 + 10);
        int x = 1e5;
        for (auto v: nums) {
            arr[v - k + x]++;
            arr[v + k + x + 1]--;
        }
        int ans = 0;
        int res = 0;
        for (auto v: arr) {
            res += v;
            ans = max(ans, res);
        }
        return ans;
    }

    int maximumBeauty2(vector<int>& nums, int k) {
        //ranges::sort(nums);
        map<int, int> arr;
        for (auto v: nums) {
            arr[v - k]++;
            arr[v + k + 1]--;
        }
        int ans = 0;
        int res = 0;
        for (auto& [_, v]: arr) {
            res += v;
            ans = max(ans, res);
        }
        return ans;
    }

    int maximumBeauty3(vector<int>& nums, int k) {
        //ranges::sort(nums);
        unordered_map<int, int> hash;
        for (auto v: nums) {
            hash[v - k]++;
            hash[v + k + 1]--;
        }
        vector<pair<int, int>> arr;
        for (auto& kv: hash) {
            arr.push_back(kv);
        }
        ranges::sort(arr);
        int ans = 0;
        int res = 0;
        for (auto& [_, v]: arr) {
            res += v;
            ans = max(ans, res);
        }
        return ans;
    }

    // 连续区间, 滑动窗口
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums);
        int len = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (nums[r] - nums[l] > k * 2) {
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,6,1,2]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n10\n
// @lcpr case=end

 */

