/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 *
 * [1317] 将整数转换为两个无零整数的和
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
    bool isNonZeroNumber(int val) {
        string str = to_string(val);
        for (char c : str) {
            if (c == '0') {
                return false;
            }
        }
        return true;
    }

    vector<int> getNoZeroIntegers1(int n) {
        for (int i = 1; i < n; ++i) {
            if ((to_string(i) + to_string(n - i)).find('0') == string::npos) {
                return {i, n - i};
            }
        }
        return {};
    }

    bool isNonZeroNumber2(int val) {
        while(val > 1) {
            int v = val % 10;
            if (v == 0) {
                return false;
            }
            val /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            if (isNonZeroNumber2(i) && isNonZeroNumber2(n - i)) {
                return {i, n - i};
            }
        }
        return {};
    }
};
// @lc code=end

