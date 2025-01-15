/*
 * @lc app=leetcode.cn id=91 lang=cpp
 * @lcpr version=30204
 *
 * [91] 解码方法
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
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= max(0, i - 1); j--) {
                if (s[j] == '0') continue;
                string code = s.substr(j, i - j + 1);
                int val = atoi(code.c_str());
                if (val >= 1 and val <= 26) f[i + 1] += f[j];
            }
        }
        return f[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "12"\n
// @lcpr case=end

// @lcpr case=start
// "226"\n
// @lcpr case=end

// @lcpr case=start
// "06"\n
// @lcpr case=end

 */

