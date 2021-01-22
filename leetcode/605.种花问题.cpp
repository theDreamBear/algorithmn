/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 添加哨兵, 简化逻辑
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int i = 1, j = flowerbed.size() - 2;
        while (i <= j && n > 0) {
            if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 &&
                flowerbed[i + 1] == 0) {
                --n;
                i += 2;
            } else {
                ++i;
            }
        }
        return n == 0;
    }

    /*
        逻辑复杂
        保证 数组不越界
    */
    bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (n == 0) {
                return true;
            } else if (flowerbed[0] == 0 && n == 1) {
                return true;
            } else {
                return false;
            }
        }
        int i = 0, j = flowerbed.size() - 1;
        while (i <= j && n > 0) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (flowerbed[i + 1] == 0) {
                        --n;
                        i += 2;
                    } else {
                        ++i;
                    }
                } else if (i == j) {
                    if (flowerbed[i - 1] == 0) {
                        --n;
                        i += 2;
                    } else {
                        ++i;
                    }
                } else {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        --n;
                        i += 2;
                    } else {
                        ++i;
                    }
                }

            } else {
                ++i;
            }
        }
        return n == 0;
    }
};
// @lc code=end
