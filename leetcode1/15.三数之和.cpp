/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 最直观的思路就是， 三层循环
        // 3e3 * 3e3 * 3e3 = 2.7e10 超时

        // target = 0 - num1 - num2
        // 存储所有的 -num1-num2, 以及下标
        // 时间复杂度 n^2, 空间复杂度 n^2
        // 应该是可以过的
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> mp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] + nums[j]].push_back({i, j});
            }
        }
        set<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (mp.count(-nums[i])) {
                for (auto& p : mp[-nums[i]]) {
                    if (p.first > i && p.second > i) {
                        vector<int> temp{nums[i], nums[p.first], nums[p.second]};
                        sort(temp.begin(), temp.end());
                        ans.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

// @lc code=end

