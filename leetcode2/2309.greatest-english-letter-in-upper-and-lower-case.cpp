/*
 * @lc app=leetcode.cn id=2309 lang=cpp
 * @lcpr version=30204
 *
 * [2309] 兼具大小写的最好英文字母
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
    string greatestLetter(string s) {
        int cnt[300]{};
        for (auto ch: s) {
            cnt[ch]++;
        }
        for (char i = 'Z'; i >= 'A'; i--) {
            if (cnt[i] and cnt[tolower(i)]) return string(1, i);
        }
        return "";
    }
};
// @lc code=end



/*
// @lcpr case=start
// "lEeTcOdE"\n
// @lcpr case=end

// @lcpr case=start
// "arRAzFif"\n
// @lcpr case=end

// @lcpr case=start
// "AbCdEfGhIjK"\n
// @lcpr case=end

 */

