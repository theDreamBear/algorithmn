/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=30204
 *
 * [6] Z 字形变换
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
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> tmp(numRows);
        int i = 0, flag = -1;
        // 循环不变量
        // 每一个状态符合
        for (int j = 0; i < s.size(); i++) {
            tmp[j] += s[i];
            if (j == 0 or j + 1 == numRows) {
                flag = -flag;
            }
            j += flag;
        }
        string ans;
        for (auto & str: tmp) {
            ans += str;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */

