/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
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
    bool isSelfDividingNumber(int val) {
        int v = val;
        while (v) {
            int d = v % 10;
            if (d == 0 || val % d != 0) {
                return false;
            }
            v = v / 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int val = left; val <= right; ++val) {
            if (val % 10 == 0) {
                continue;
            }
            if (isSelfDividingNumber(val)) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
// @lc code=end

