/*
 * @lc app=leetcode.cn id=97 lang=cpp
 * @lcpr version=30116
 *
 * [97] 交错字符串
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
    bool isInterleave(string& s1, string& s2, string& s3, int x, int y, vector<vector<int>>& memo) {
        if (x >= s1.size() and y >= s2.size()) {
            return true;
        }
        if (x >= s1.size() or y >= s2.size()) {
            if (x >= s1.size()) {
                return !strcmp(s2.c_str() + y, s3.c_str() + x + y);
            } else {
                return !strcmp(s1.c_str() + x, s3.c_str() + x + y);
            }
        }
        if (memo[x][y] != -1) {
            return memo[x][y];
        }
        return memo[x][y] = (s1[x] == s3[x + y] and isInterleave(s1, s2, s3, x + 1, y, memo))
                         or (s2[y] == s3[x + y] and isInterleave(s1, s2, s3, x, y + 1, memo))
                         or 0;
    }


    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), mn = s3.size();
        if (m + n != mn) {
            return false;
        }
        vector<vector<int>> memo(m, vector<int>(n, - 1));
        return isInterleave(s1, s2, s3, 0, 0, memo);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbcbcac"\n
// @lcpr case=end

// @lcpr case=start
// "aabcc"\n"dbbca"\n"aadbbbaccc"\n
// @lcpr case=end

// @lcpr case=start
// ""\n""\n""\n
// @lcpr case=end

 */

