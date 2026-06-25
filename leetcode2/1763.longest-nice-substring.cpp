/*
 * @lc app=leetcode.cn id=1763 lang=cpp
 * @lcpr version=30204
 *
 * [1763] 最长的美好子字符串
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
    string longestNiceSubstring(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++) {
            int low = 0, high = 0;
            auto add = [&](char ch) {
                if (islower(ch)) low |= (1 << (ch - 'a'));
                else high |=  (1 << (ch - 'A'));
            };
            for (int j = i; j < s.size(); j++) {
                add(s[j]);
                if (low == high and j - i + 1 > ans.size()) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "YazaAay"\n
// @lcpr case=end

// @lcpr case=start
// "Bb"\n
// @lcpr case=end

// @lcpr case=start
// "c"\n
// @lcpr case=end

// @lcpr case=start
// "dDzeE"\n
// @lcpr case=end

 */

