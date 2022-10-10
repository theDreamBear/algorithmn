/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
#ifdef VIOLATE
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // O(n^3)
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] > nums[k]) {
                        ++ans;
                    } else {
                        break;
                    }
                }
            }
        }
#elif VIOLATE_BINARY
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // O(n^2 * lgn)
                int sum = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), sum);
                ans += (it - nums.begin() - 1 - j);
            }
        }
#else
        //
        for (int i = 0; i < n; i++) {
            int k = i + 2;
            for (int j = i + 1; j < n; j++) {
                if (k <= j) {
                    k = j + 1;
                }
                // O(n^2 * lgn)
                int sum = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + k, nums.end(), sum);
                k = it - nums.begin();
                ans += (k - j - 1);
            }
        }
#endif
        return ans;
    }
};
// @lc code=end

