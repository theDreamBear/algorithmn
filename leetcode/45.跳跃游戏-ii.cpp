/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ranges.h>

using namespace std;
// @lc code=start
class Solution {
public:
    /*
        状态定义dp[i] 从0 到 i 最少跳跃次数
        状态转移方程 
        dp[i + j] = min(dp[i + j], dp[i] + 1 ) (0 < j <= nums[i])
        ans : dp.back();
                  
    */
    int jump1(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = nums[i]; j > 0; --j) {
                if ((i + j < nums.size()) && (dp[i + j] > dp[i] + 1)) {
                    dp[i + j] = dp[i] + 1;
                }
            }
        }
        return dp.back();
    }

    /*
        贪心
        每一步选择选择其就能到最远的点的点
    */
    int jump(vector<int>& nums) {
        int max_far = 0, end = 0, step = 0;
        for(int i = 0; i < nums.size(); ++i) { 
            // 覆盖只有一个点的情况
            if (end >= nums.size() - 1) {
                break;
            }
            max_far = max(max_far, i + nums[i]);
            if (i == end) {
                end = max_far;
                ++step;
            }
        }
        return step;
    }

};
// @lc code=end

int main() {
    vector<int> data{2,3,1,1,4};
    cout << Solution{}.jump(data);
}