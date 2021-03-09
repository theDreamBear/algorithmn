/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 *
 * [1137] 第 N 个泰波那契数
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
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n <= 2) {
            return 1;
        }
        int ppp = 0;
        int pp = 1;
        int p = 1;
        for (int i = 3; i <= n; ++i) {
            int temp = p + pp + ppp;
            ppp = pp;
            pp = p;
            p = temp;
        }
        return p;
    }
};
// @lc code=end

