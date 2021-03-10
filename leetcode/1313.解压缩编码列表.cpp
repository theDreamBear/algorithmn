/*
 * @lc app=leetcode.cn id=1313 lang=cpp
 *
 * [1313] 解压缩编码列表
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
    vector<int> decompressRLElist1(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(1000);
        for (int i = 0; i < nums.size(); i += 2) {
            int times = nums[i];
            int val = nums[i + 1];
            for (int j = 0; j < times; ++j) {
                ans.emplace_back(val);
            }
        }
        return ans;
    }

    /*
        先求大小再塞值
    */
    vector<int> decompressRLElist(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            len += nums[i];
        }
        vector<int> ans(len);
        int index = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            int times = nums[i];
            int val = nums[i + 1];
            for (int j = 0; j < times; ++j) {
                ans[index++] = val;
            }
        }
        return ans;
    }
};
// @lc code=end

