/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
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
    int oddCells1(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n);
        vector<int> cols(m);
        for (auto& vec : indices) {
            ++rows[vec[0]];
            ++cols[vec[1]];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans += ((rows[i] + cols[j]) % 2 != 0);
            }
        }
        return ans;
    }

    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> rows(n);
        vector<int> cols(m);
        for (auto& vec : indices) {
            ++rows[vec[0]];
            ++cols[vec[1]];
        }
        int ans = 0;
        /*
            最终为奇数的空格, 必然属于 行偶+ 列奇 或者 行奇+列偶
        */
        int row_even = 0, row_odd = 0;
        for (auto val : rows) {
            if (val % 2 == 0) {
                row_even++;
            } else {
                row_odd++;
            }
        }
        int col_even = 0, col_odd = 0;
        for (auto val : cols) {
            if (val % 2 == 0) {
                col_even++;
            } else {
                col_odd++;
            }
        }
        return row_even * col_odd + row_odd * col_even;
    }
};
// @lc code=end

