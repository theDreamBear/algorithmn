/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30204
 *
 * [438] 找到字符串中所有字母异位词
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};
        vector<int> ans;
        int cnt[26];
        int type = 0;
        for (auto ch: p) {
            if (++cnt[ch - 'a'] == 1) type++;
        }
        // 定滑动窗口
        for (int i = 0; i + 1 < p.size(); i++) {
            if (--cnt[s[i] - 'a'] == 0) {
                type--;
            }
        }
        for (int i = p.size() - 1; i < s.size(); i++) {
            if (--cnt[s[i] - 'a'] == 0) {
                type--;
            }
            if (type == 0) ans.push_back(i - p.size() + 1);
            if (++cnt[s[i - p.size() + 1] - 'a'] == 1) {
                type++;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

