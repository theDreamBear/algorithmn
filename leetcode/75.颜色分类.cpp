/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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
    void sortColors_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
    }

    /*
        [0, p1)  0
        [p1, i)  1
        (p2, len - 1]  2

    */
    void sortColors1(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int p1 = 0;
        int i = 0;
        int p2 = nums.size() - 1;
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p1]);
                ++p1;
                ++i;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[p2]);
                --p2;
            }
        }
    }

    /*
    p0 0第一个交换位置
    p1 1 第一个交换位置
    
    【0， p0) 是0的区间

    */
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int p0 = 0;
        int p1 = 0;
        int i = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};
// @lc code=end

