/*
 * @lc app=leetcode.cn id=1675 lang=cpp
 *
 * [1675] 数组的最小偏移量
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
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
     *  nlgn 或者 n
     *
     * */
    int minimumDeviation(vector<int> &nums) {
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            data.emplace_back(value, i);
            if (value % 2 == 0) {
                while (value % 2 == 0) {
                    value >>= 1;
                    data.emplace_back(value, i);
                }
            } else {
                data.emplace_back(value << 1, i);
            }
        }
        sort(data.begin(), data.end());
        vector<int> dp(nums.size());
        int ans = INT_MAX;
        int left = nums.size();
        int low = 0, high = 0;
        while (high < data.size()) {
            auto[v, index] = data[high];
            if (++dp[index] == 1) {
                --left;
                if (left == 0) {
                    auto p = data[low];
                    while (dp[p.second] > 1) {
                        --dp[p.second];
                        ++low;
                        p = data[low];
                    }
                    ans = min(ans, v - p.first);
                    --dp[p.second];
                    ++low;
                    ++left;
                }
            }
            ++high;
        }
        return ans;
    }
};
// @lc code=end

