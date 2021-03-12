/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
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
        问题分析
            1. nums[i] - nums[j] 会越界
            2. 时间复杂度, nk;
        思考: n 是变不了的, 怎么改变 k
            我们每次是在前面k 的元素里面找[nums[i] - t, nums[i] + t] 范围内的元素
            这种可以通过 set 配合二分来实现
    */
     bool containsNearbyAlmostDuplicate1(vector<int>& nums, int k, int t) {
         for (int i = 1; i < nums.size(); ++i) {
             for (int j = max(0, i - k); j < i; ++j) {
                 if (abs(nums[i] - nums[j]) <= t) {
                     return true;
                 }
             }
         }
         return false;
     }

    /*
        史上最坑的一道题
        约束条件一个不给
        + - 发会引发越界
        时间复杂度 nlgk
    */
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) {
            return false;
        }
        long long diff = 0;
        if (k == 1) {
            for (int i = 1; i < nums.size(); ++i) {
                diff = abs((long long)nums[i - 1] - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            return false;
        }
        set<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 找第一个比自己小t的
            auto pos = s.lower_bound((long long)nums[i] - t);
            if (pos != s.end()) {
                diff = abs((long long)*pos - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            // 找第一个大于等于自己的
            pos = s.lower_bound(nums[i]);
            if (pos != s.end()) {
                diff = abs((long long)*pos - nums[i]);
                if (diff <= t) {
                    return true;
                }
            }
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};
// @lc code=end

