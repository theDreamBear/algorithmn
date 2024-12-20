/*
 * @lc app=leetcode.cn id=2370 lang=cpp
 * @lcpr version=30204
 *
 * [2370] 最长理想子序列
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
    int longestIdealString1(string s, int k) {
        int n = s.size();
        // 枚举右维护左, 聚合
        int cnt[26]{};
        for (int i = 0; i < s.size(); i++) {
            int res = cnt[s[i] - 'a'];
            for (int ch = s[i] - k; ch <= s[i] + k; ch++) {
                if (ch >= 'a' and ch <= 'z') {
                    res = max(res, cnt[ch - 'a'] + 1);
                }
            }
            cnt[s[i] - 'a'] = res;
        }
        return ranges::max(cnt);
    }

    int longestIdealString(string s, int k) {
        int n = s.size();
        // 枚举右维护左, 聚合
        int cnt[26]{};
        for (char ch: s) {
            ch -= 'a';
            cnt[ch] = 1 + *max_element(cnt + max(ch - k, 0), cnt + min(ch + k + 1, 26));
        }
        return ranges::max(cnt);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "acfgbd"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n3\n
// @lcpr case=end

 */

