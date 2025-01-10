/*
 * @lc app=leetcode.cn id=3270 lang=cpp
 * @lcpr version=30204
 *
 * [3270] 求出数字答案
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
    int generateKey(int num1, int num2, int num3) {
        auto s1 = to_string(num1), s2 = to_string(num2), s3 = to_string(num3);
        if (s1.size() < 4) s1 = string(4 - s1.size(), '0') + s1;
        if (s2.size() < 4) s2 = string(4 - s2.size(), '0') + s2;
        if (s3.size() < 4) s3 = string(4 - s3.size(), '0') + s3;
        string ans(4, '0');
        for (int i = 0; i < 4; i++) {
            ans[i] = min({s1[i], s2[i], s3[i]});
        }
        return atoi(ans.c_str());
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n10\n1000\n
// @lcpr case=end

// @lcpr case=start
// 987\n879\n798\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n3\n
// @lcpr case=end

 */

