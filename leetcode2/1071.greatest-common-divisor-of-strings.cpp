/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 * @lcpr version=30204
 *
 * [1071] 字符串的最大公因子
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
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string gcdOfStrings1(string str1, string str2) {
        int n = min(str1.size(), str2.size());
        auto ismatch = [&](string s, string match) {
            for (int i = 0, j = 0; i < s.size(); i++) {
                if (s[i] == match[j]) {
                    if (++j == match.size()) j = 0;
                } else {
                    return false;
                }
            }
            return true;
        };
        for (int i = n; i >= 1; i--) {
            if (str1.size() % i == 0 and str2.size() % i == 0) {
                string mathch = str1.substr(0, i);
                if (ismatch(str1, mathch) and ismatch(str2, mathch)) return mathch;
            }
        }
        return "";
    }

    // 一定是最大公约数

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) return "";
        int g = gcd(str1.size(), str2.size());
        return str1.substr(0, g);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "ABCABC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "ABABAB"\n"ABAB"\n
// @lcpr case=end

// @lcpr case=start
// "LEET"\n"CODE"\n
// @lcpr case=end

 */

