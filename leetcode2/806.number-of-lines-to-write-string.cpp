/*
 * @lc app=leetcode.cn id=806 lang=cpp
 * @lcpr version=30204
 *
 * [806] 写字符串需要的行数
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
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int maxWith = 100;
        int ans = 0, now = 100;
        for (auto ch: s) {
            int need = widths[ch - 'a'];
            if (now + need <= maxWith) now += need;
            else {
                ans++;
                now = need;
            }
        }
        return {ans, now};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10\n"abcdefghijklmnopqrstuvwxyz"\n
// @lcpr case=end

// @lcpr case=start
// [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10\n"bbbcccdddaaa"\n
// @lcpr case=end

 */

