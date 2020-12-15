/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
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

using namespace std;

// @lc code=start
class Solution {
public:
    bool canEatAll(const vector<int>& piles, int k, int h) {
        int cost = 0;
        for (auto x : piles) {
            int c = x / k;
            cost += c;
            if (x % k != 0) {
                ++cost;
            }
            //  更加高级的方法
            // cost += ((x - 1) / k + 1);
        }
        return cost <= h;
    }

    /*
        二分枚举
    */
    // int minEatingSpeed_binary_search(vector<int>& piles, int H) {
    //     int low = 1, high = 1e9;
    //     while (low + 1 < high) {
    //         int mid = (high - low) / 2 + low;
    //         if (canEatAll(piles, mid, H)) {
    //             high = mid;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     if (canEatAll(piles, low, H)) {
    //         return low;
    //     }
    //     return high;
    // }

    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1e9;
        while (low + 1 < high) {
            int mid = (high - low) / 2 + low;
            if (canEatAll(piles, mid, H)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (canEatAll(piles, low, H)) {
            return low;
        }
        return high;
    }
};
// @lc code=end

