/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    vector<int> findErrorNums1(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            res ^= (i ^ nums[i - 1]);
        }
        int rep = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                break;
            }
        }
        int miss = res ^ rep;
        return {rep, miss};
    }
    /*
        how to avoid complex
        寻找重复数很简单
    */
    vector<int> findErrorNums2(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int miss = 0, rep = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                nums[i] = 0;
                break;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            miss ^= (i + 1) ^ nums[i];
        }
        return {rep, miss};
    }

    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int miss = 0, rep = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                nums[i] = 0;
                break;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            miss ^= (i + 1) ^ nums[i];
        }
        return {rep, miss};
    }
};
// @lc code=end
