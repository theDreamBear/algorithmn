/*
 * @lc app=leetcode.cn id=2337 lang=cpp
 * @lcpr version=30204
 *
 * [2337] 移动片段得到字符串
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
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n and j < n) {
            while (i < n and start[i] == '_') i++;
            while (j < n and target[j] == '_') j++;
            if (i >= n or j >= n) break;
            if (start[i] != target[j]) break;
            if (start[i] == 'L') {
                if (i < j) break;
            }
            if (start[i] == 'R') {
                if (i > j) {
                    break;
                }
            }
            i++;
            j++;
        }
        while (i < n and start[i] == '_') i++;
        while (j < n and target[j] == '_') j++;
        return i == n and j == n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "_L__R__R_"\n"L______RR"\n
// @lcpr case=end

// @lcpr case=start
// "R_L_"\n"__LR"\n
// @lcpr case=end

// @lcpr case=start
// "_R"\n"R_"\n
// @lcpr case=end

 */

