/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 * @lcpr version=30204
 *
 * [1422] 分割字符串的最大得分
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
    int maxScore(string s) {
        int ans = 0;
        int cto = 0;
        for (auto ch: s) {
            if (ch == '1') cto++;
        }
        int ctz = 0;
        // if (s[0] == '0') ctz++;
        // else cto--;
        // ans = max(ans, ctz + cto);
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == '0') ctz++;
            else cto--;
            ans = max(ans, ctz + cto);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "011101"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

 */

