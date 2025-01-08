/*
 * @lc app=leetcode.cn id=面试题 05.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.02] 二进制数转字符串
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <bits/stdc++.h>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string printBin(double num) {
        double cur = 0.5;
        string ans = "0.";
        for (int i = 0; i < 10 and abs(num) > 1e-8; i++) {
            if (num >= cur) {
                ans += '1';
                num -= cur;
            } else {
                ans += '0';
            }
            cur /= 2;
        }
        if (abs(num) > 1e-8) return "ERROR";
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 0.625\n
// @lcpr case=end

// @lcpr case=start
// 0.1\n
// @lcpr case=end

 */

