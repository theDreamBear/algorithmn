/*
 * @lc app=leetcode.cn id=1295 lang=cpp
 *
 * [1295] 统计位数为偶数的数字
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
    // to_string 获得每一位这方法也不错

    int findNumbers1(vector<int>& nums) {
        int ans = 0;
        vector<int> data = {0, 10, 100, 1000, 10000, 100000, 1000000};
        for (auto val : nums) {
            auto p = upper_bound(data.begin(), data.end(), val);
            if ((p - data.begin()) % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }

     int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int i : nums)
            if ((i >= 10 && i < 100) || (i >= 1000 && i < 10000) || i == 100000)
                res ++;
        return res;
    }
};
// @lc code=end

