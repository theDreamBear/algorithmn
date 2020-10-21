/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 public:
    /*
    暴力解法, 挑选两个柱子, 算面积, 超时 n^2
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

    int maxArea_2(vector<int>& height) {
        vector<pair<int, int>> mp;
        for (int i = 0; i < height.size(); ++i) {
            mp.push_back({height[i], i});
        }
        // nlgn
        sort(mp.begin(), mp.end(), less<pair<int, int>>());
        vector<bool> used(height.size(), 0);
        int mArea = 0;
        int left = 0, right = height.size() - 1;
        for (auto kv = mp.begin(); left < right && kv != mp.end(); ++kv) {
            int area = (right - left) * kv->first;
            if (area > mArea) {
                mArea = area;
            }
            used[kv->second] = true;
            if (kv->second == left) {
                while (left < right && used[++left])
                    ;
            }
            if (kv->second == right) {
                while (left < right && used[--right])
                    ;
            }
        }
        return mArea;
    }

    int maxArea(vector<int>& height) {
        int mArea = 0;
        int left = 0, right = height.size() - 1;
        for (; left < right;) {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            if (area > mArea) {
                mArea = area;
            }
            if (height[left] < height[right]) {
                while (left < right && height[++left] < h)
                    ;
            } else {
                while (left < right && height[--right] < h)
                    ;
            }
        }
        return mArea;
    }
};
// @lc code=end

int main() {
    vector<int> h = {1, 0, 0, 0, 0, 0, 0, 2, 2};
    Solution s;
    cout << s.maxArea(h);
}