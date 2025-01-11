/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 * @lcpr version=30204
 *
 * [1189] “气球” 的最大数量
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
    int maxNumberOfBalloons(string text) {
        int cnt[26]{};
        for (auto ch: text) {
            cnt[ch - 'a']++;
        }
        auto get = [&](char ch) {
            return cnt[ch - 'a'];
        };
        return min({get('a'), get('b'), get('l') / 2, get('o') / 2, get('n')});
    }
};
// @lc code=end



/*
// @lcpr case=start
// "nlaebolko"\n
// @lcpr case=end

// @lcpr case=start
// "loonbalxballpoon"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n
// @lcpr case=end

 */

