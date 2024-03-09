/*
 * @lc app=leetcode.cn id=LCR 007 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 007] 三数之和
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
    vector<vector<int>> threeSum1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            if (i + 1 < nums.size() and nums[i + 1] > -nums[i]) {
                break;
            }
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while (left < right) {
                if (nums[left] + nums[right] > target) {
                    --right;
                } else if (nums[left] + nums[right] < target) {
                    ++left;
                } else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    //
                    int val = nums[left];
                    while (left < right and nums[left] == val) {
                        ++left;
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 and nums[i] == nums[i - 1]) {
                continue;
            }
            if (i + 1 < nums.size() and nums[i + 1] > -nums[i]) {
                break;
            }
            int target = -nums[i];
            for (int left = i + 1, right = nums.size() - 1; left < right; ++left) {
                if (left > i + 1 and nums[left] == nums[left - 1]) {
                    continue;
                }
                while (left < right && nums[left] + nums[right] > target) {
                    --right;
                }
                if (left == right) {
                    break;
                }
                if (nums[left] + nums[right] == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

