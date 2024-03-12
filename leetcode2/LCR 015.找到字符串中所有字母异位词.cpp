/*
 * @lc app=leetcode.cn id=LCR 015 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 015] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size()) {
            return ans;
        }
        int  alpha_cnt = 0;
        int ct[26]{0};
        for (int i = 0; i < p.size(); i++) {
            if (++ct[p[i] - 'a'] == 1) {
                ++alpha_cnt;
            }
        }
        for (int i = 0; i + 1 < p.size(); i++) {
            if (--ct[s[i] - 'a'] == 0) {
                --alpha_cnt;
            }
        }
        for (int i = p.size() - 1; i < s.size(); i++) {
            if (--ct[s[i] - 'a'] == 0) {
                if (--alpha_cnt == 0) {
                    ans.push_back(i - p.size() + 1);
                }
            }
            if (++ct[s[i - p.size() + 1] - 'a'] == 1) {
                ++alpha_cnt;
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

