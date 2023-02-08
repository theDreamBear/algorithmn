/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            int idx = 0;
            for (int j = 1; j <= i; j++) {
                if (arr[j] > arr[idx]) {
                    idx = j;
                }
            }
            if (idx < i) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);

                reverse(arr.begin(), arr.begin() + i + 1);
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
// @lc code=end

