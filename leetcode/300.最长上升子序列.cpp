/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <iostream>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
 public:
    int bsearch(const vector<int>& arr, const vector<int>& nums, int index) {
        int low = 0, high = arr.size() - 1;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (nums[arr[mid]] >= nums[index]) {
                high = mid - 1;
            } else {
                low = mid;
            }
        }
        if (nums[arr[high]] < nums[index]) {
            return arr[high];
        }
        if (nums[arr[low]] < nums[index]) {
            return arr[low];
        }
        return -1;
    }

    /*
        定义: dp[i]是以nums[i] 结尾的最大长度
        转态方程: if nums[i] > nums[j] dp[i] = max(dp[i], dp[j - 1] + 1), j 的范围 [i - 1, 0, -1]
        初始化 dp[i] = 1;
        结果: max(dp[i]);

        复杂度分析:
            时间复杂度 O(n^2)
            空间复杂度 O(n)
        性能瓶颈在以第二层循环的遍历太慢,

    */
    #define VIOLATE
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        vector<int> slowest;
        int ans = 1;
        slowest.push_back(0);
        for (int i = 1; i < nums.size(); ++i) {
#ifdef VIOLATE
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > ans) {
                        ans = dp[i];
                    }
                }
            }
#else

#endif

        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout << Solution{}.lengthOfLIS(arr);
}