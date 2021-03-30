/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
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
    int valid(string& s, int low, int high) {
        if (low == high) {
            if (s[low] == '0') {
                return 0;
            }
            return 1;
        } else {
            if (s[low] == '0') {
                return 0;
            }
            if (s[low] > '2' || (s[low] == '2' && s[high] > '6')) {
                return 0;
            }
            return 1;
        }
    }

    /*
        求sum, 可知用动态规划算法
    */
    int numDecodings1(string s) {
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            if (valid(s, i - 1, i - 1)) {
                dp[i] += dp[i - 1];
            }
            if (i - 2 >= 0 && valid(s, i - 2, i - 1)) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }

    /*
        优化上面的算法， 发现只需要记录两个值
    */
    int numDecodings(string s) {
        int lastlast = 1, last = 1;
        for (int i = 0; i < s.size(); ++i) {
            int now = 0;
            if (valid(s, i, i)) {
                now += last;
            }
            if (i - 1 >= 0 && valid(s, i - 1, i)) {
                now += lastlast;
            }
            lastlast = last;
            last = now;
        }
        return last;
    }
};
// @lc code=end

int main() {
    string s = "226";
    cout << Solution{}.numDecodings(s);
}