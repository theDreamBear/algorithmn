/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include <ranges.h>
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
    /*
        存起来计数
    */
    vector<int> majorityElement1(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto val : nums) {
            ++hash[val];
        }
        vector<int> ans;
        int n = nums.size();
        for (auto& kv : hash) {
            if (kv.second > n / 3) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }

    /*
        排序
    */
    vector<int> majorityElement2(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int i = 0;
        int v = nums[0];
        while (i < n) {
            int ct = 0;
            while (i < n && nums[i] == v) {
                ++ct;
                ++i;
            }
            if (ct > n / 3) {
                ans.push_back(v);
            }
            if (i < n) {
                v = nums[i];
            }
        }
        return ans;
    }

    /*
        摩尔投票法， 套路题
    */
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return nums;
        }  
        vector<int> ans;
        int first = nums[0], ft = 0;
        int second = nums[0], st = 0;
        int i = 0;
        for (; i < n; ++i) {
            if (nums[i] == first) {
                ++ft;
                continue;
            }
            if (nums[i] == second) {
                ++st;
                continue;
            }
            if (ft == 0) {
                first = nums[i];
                ft = 1;
                continue;
            }
            if (st == 0) {
                second = nums[i];
                st = 1;
                continue;
            }
            --ft;
            --st;
        }
        int ct1 = 0, ct2 = 0;
        for (auto val : nums) {
            if (val == first) {
                ++ct1;
                continue;
            } 
            if (val == second) {
                ++ct2;
            }
        }
        if (ct1 > n / 3) {
            ans.push_back(first);
        }
        if (ct2 > n / 3) {
            ans.push_back(second);
        }
        return ans;
    }
};
// @lc code=end
