/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <stack>
#include <map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
    /*
    暴力解法, 挑选两个柱子, 算面积, 超时
    */
    int maxArea_violate(vector<int>& height) {
        int mArea = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int width = i - j;
                int h = min(height[i], height[j]);
                int area = width * h;
                if (area > mArea) {
                    mArea = area;
                }
            }
        }
        return mArea;
    }

    int maxArea(vector<int>& height) {
        int mArea = 0;
        map<int, int> mp;
        for (int i = 0; i < height.size(); ++i) {
            mp[height[i]] = i;
        }
        for (auto& kv : mp) {
            
        }
        return mArea;
    }
};
// @lc code=end
