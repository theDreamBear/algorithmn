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
        

    */
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) {
            return;
        }
        int p0 = 0;
        int p1 = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 0) {
                swap(nums[p0], nums[i]);
                ++p0;
                ++i;
            } else if(nums[i] == 1) {
                if (p0 > p1) {
                    swap(nums[p0], nums[i]);
                    p1 = p0 + 1;
                } else {
                    swap(nums[i], nums[p1]);
                    ++p1;
                    ++i;
                }
            } else {
                ++i;
            }
        }
    }
};
// @lc code=end

