/*
 * @lc app=leetcode.cn id=1184 lang=cpp
 *
 * [1184] 公交站间的距离
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
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d = 0;
        // 起点到终点 顺时针
        for (int i = start;; ++i) {
            if (i == distance.size()) {
                i = 0;
            }
            if (i == destination) {
                break;
            }
            d += distance[i];
        }
        int d1 = 0;

        //终点到起点顺时针
        for (int j = destination; ;++j) {
            if (j == distance.size()) {
                j = 0;
            }
            if (j == start) {
                break;
            }
            d1 += distance[j];
        }
        return min(d, d1);
    }
};
// @lc code=end

