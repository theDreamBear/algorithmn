/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_positive_diff = 1e6;
        int min_negative_diff = -1e6;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i - 1 > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;
            for (; j < k; ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                int diff = nums[i] + nums[j] + nums[k] - target;
                if (diff > 0) {
                    --k;
                    if (diff < min_positive_diff) {
                        min_positive_diff = diff;
                    }
                } else if (diff < 0) {
                    ++j;
                    if (diff > min_negative_diff) {
                        min_negative_diff = diff;
                    }
                } else {
                    return target;
                }
            }
        }
        if (abs(min_negative_diff) > min_positive_diff) {
            return target + min_positive_diff;
        }
        return target + min_negative_diff;
    }
};
// @lc code=end

