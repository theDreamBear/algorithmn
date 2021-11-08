/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
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
    int specialArray1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int value = nums.size();
        for (; value >= 0; value--) {
            int ct = 0;
            for(int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] >= value) {
                    ++ct;
                } else {
                    break;
                }
            }
            if (value == ct) {
                break;
            }
        }
        return value;
    }

    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int value = nums.size();
        for (; value >= 0; value--) {
            auto p = nums.end() -  lower_bound(nums.begin(), nums.end(), value);
            if (p == value) {
                break;
            }
        }
        return value;
    }
};
// @lc code=end

