/*
 * @lc app=leetcode.cn id=3274 lang=cpp
 * @lcpr version=30204
 *
 * [3274] 检查棋盘方格颜色是否相同
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
    bool checkTwoChessboards(string s1, string s2) {
        // & ^ |
        //return (((s1[0] - 'a') ^ (s1[1] - '1')) & 1) == (((s2[0] - 'a') ^ (s2[1] - '1')) & 1);
        return ((s1[0] ^ s1[1]) & 1) == ((s2[0] ^ s2[1]) & 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "a1"\n"c3"\n
// @lcpr case=end

// @lcpr case=start
// "a1"\n"h3"\n
// @lcpr case=end

 */

