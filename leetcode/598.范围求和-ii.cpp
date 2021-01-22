/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
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
    // void update(vector<vector<int>>& source, int a, int b) {
    //     for (int i = 0; i < a; ++i) {
    //         for (int j = 0; j < b; ++j) {
    //             ++source[i][j];
    //         }
    //     }
    // }
    void findMinArea(pair<int, int>& left, pair<int, int> right) {
        if (left.first > right.first) {
            left.first = right.first;
        }
        if (left.second > right.second) {
            left.second = right.second;
        }
    }


    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return m * n;
        }
        pair<int, int> vv(INT_MAX, INT_MAX);
        for (auto& vec : ops) {
            int a = vec[0];
            int b = vec[1];
            findMinArea(vv, pair<int, int>(a, b));
        }
        return vv.first * vv.second;
    }
};
// @lc code=end

