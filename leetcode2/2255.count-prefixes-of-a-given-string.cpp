/*
 * @lc app=leetcode.cn id=2255 lang=cpp
 * @lcpr version=30204
 *
 * [2255] 统计是给定字符串前缀的字符串数目
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
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto& w: words) {
            int sz = w.size();
            if (s.substr(0, sz) == w) {
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["a","b","c","ab","bc","abc"]\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// ["a","a"]\n"aa"\n
// @lcpr case=end

 */

