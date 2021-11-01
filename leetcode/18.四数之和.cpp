/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <ranges.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// @lc code=start
class Solution1 {
 public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = 0; i + 3 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[len - 1] + nums[len - 2] + nums[len - 3] <
                target)
                continue;
            for (int j = i + 1; j + 2 < nums.size(); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[len - 1] + nums[len - 2] <
                    target) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back( {nums[i], nums[j], nums[left], nums[right]} );
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                        continue;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }
        return ans;
    }
};


vector<vector<int>> nSumHelper(const vector<int> &nums, vector<int> &before, int n, int target) {
    vector<vector<int>> res;
    if (n <= 0) {
        return res;
    }
    if (n == 1) {
        for (auto value : nums) {
            if (value == target) {
                res.push_back({value});
            }
        }
        return res;
    }
    if (n == 2) {
        int i = -1;
        if (!before.empty()) {
            i = before.back();
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (left < right) {
            vector<int> temp = before;
            int sum = nums[left] + nums[right];
            if (sum == target) {
                temp.push_back(left);
                temp.push_back(right);
                vector<int> t;
                for (auto index : temp) {
                    t.push_back(nums[index]);
                }
                res.push_back(move(t));
                ++left;
                --right;
                while (left < right && nums[left] == nums[left - 1]) {
                    ++left;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    --right;
                }
                continue;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
    int i = -1;
    if (!before.empty()) {
        i = before.back();
    }
    for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
            continue;
        }
        before.push_back(j);
        auto r1 = nSumHelper(nums, before, n - 1, target - nums[j]);
        if (!r1.empty()) {
            for (auto &v : r1) {
                res.push_back(v);
            }
        }
        before.pop_back();
    }
    return res;
}

vector<vector<int>> nSum(vector<int> &nums, int n, int target) {
    vector<vector<int>> ans;
    if (nums.size() < n) {
        return ans;
    }
    sort(nums.begin(), nums.end());
    vector<int> before;
    return nSumHelper(nums, before, n, target);
}
///    ===============提交的业务代码=============================
class Solution {
 public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return nSum(nums, 4, target);
    }
};

// @lc code=end
