/*
 * @lc app=leetcode.cn id=2384 lang=cpp
 * @lcpr version=30204
 *
 * [2384] 最大回文数字
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
    string largestPalindromic(string num) {
        int cnt[10]{};
        for (auto ch: num) {
            cnt[ch - '0']++;
        }
        string pre;
        int ma = -1;
        for (int i = 9; i >= 0; i--) {
            if(cnt[i]) {
                int half = cnt[i] / 2;
                if (!(pre.empty() and i == 0) and half) {
                    pre += string(half, '0' + i);
                }
                if (cnt[i] % 2 == 1 and ma == -1) {
                    ma = i;
                }
            }
        }
        auto post = pre;
        ranges::reverse(post);
        if (pre.empty() and ma == -1) {
            return "0";
        }
        if (ma == -1) {
            return pre + post;
        }
        return pre + char(ma + '0') + post;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "444947137"\n
// @lcpr case=end

// @lcpr case=start
// "00009"\n
// @lcpr case=end

 */

