/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
 public:
    int firstMissingPositive_violate(vector<int>& nums) {
        unordered_set<int> hs;
        for (auto v : nums) {
            if (v > 0 && hs.count(v) == 0) {
                hs.insert(v);
            }
        }
        int i = 1;
        for (; i <= hs.size(); i++) {
            if (hs.count(i) == 0) {
                break;
            }
        }
        return i;
    }

    int firstMissingPositive_violate2(vector<int>& nums) {
        set<int> hs;
        for (auto v : nums) {
            if (v > 0 && hs.count(v) == 0) {
                hs.insert(v);
            }
        }
        int i = 1;
        for (auto v : nums) {
            if (i != v) {
                break;
            }
        }
        return i;
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while(true) {
                if (nums[i] <= 0 || nums[i] >= nums.size()) {
                    break;
                }
                if (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                    swap(nums[nums[i] - 1], nums[i]);
                } else {
                    break;
                }
            }
        }
        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                break;
            }
        }
        return i + 1;
    }
};
// @lc code=end

