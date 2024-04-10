/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 * @lcpr version=30121
 *
 * [2606] 找到最大开销的子字符串
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int ah[26];
        iota(begin(ah), end(ah), 1);
        for (int i = 0; i < chars.size(); i++) {
            ah[chars[i] - 'a'] = vals[i];
        }
        int ans = 0;
        int cur = 0;
        for (auto ch : s) {
            if (cur <= 0) {
                cur = ah[ch - 'a'];
            } else {
                cur += ah[ch - 'a'];
            }
            ans = max(ans, cur);
        }
        return ans < 0 ? 0 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "adaa"\n"d"\n[-1000]\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"abc"\n[-1,-1,-1]\n
// @lcpr case=end

 */

