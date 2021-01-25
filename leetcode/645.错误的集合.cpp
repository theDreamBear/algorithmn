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

    vector<int> findErrorNums3(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int miss = 0, rep = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                rep = nums[i];
                break;
            }
        }
        int sz = nums.size();
        if (nums[0] != 1) {
            miss = 1;
        } else if (nums[sz - 1] != sz) {
            miss = sz;
        } else {
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] - nums[i - 1] == 2) {
                    miss = nums[i] - 1;
                    break;
                }
            }
        }
        return {rep, miss};
    }

    vector<int> findErrorNums4(vector<int>& nums) {
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        int rightBitZero = res & (-res);
        for (int i = 0; i < nums.size(); ++i) {
            if ((nums[i] & rightBitZero) == 0) {
                left ^= nums[i];
            } else {
                right ^= nums[i];
            }
            if (((i + 1) & rightBitZero) == 0) {
                left ^= (i + 1);
            } else {
                right ^= (i + 1);
            }
        }
        for (auto val : nums) {
            if (left == val) {
                return {left, right};
            } else if (right == val) {
                return {right, left};
            }
        }
        return {0, 0};
    }

    /*
        排序 nlgn
        不排序 map  n
        不排序 不 map n^2
        位操作 n
        特许标记法

    */
    vector<int> findErrorNums(vector<int>& nums) {
        int rep = 0, miss = 0;
        for (auto val : nums) {
            if (nums[abs(val) - 1] < 0) {
                rep = abs(val);
            } else {
                nums[abs(val) - 1] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                miss = i + 1;
            }
        }
        return {rep, miss};
    }
};
// @lc code=end
