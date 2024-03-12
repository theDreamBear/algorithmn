/*
 * @lc app=leetcode.cn id=LCR 014 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 014] 字符串的排列
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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        // 两根指针
        int alpha_cnt = 0;
        int ct[26] = {0};
        for (auto ch : s1) {
            if (++ct[ch - 'a'] == 1) {
                alpha_cnt++;
            }
        }
        for (int i = 0; i + 1 < s1.size(); i++) {
            if (--ct[s2[i] - 'a'] == 0) {
                --alpha_cnt;
            }
        }
        for (int i = s1.size() - 1; i < s2.size(); i++) {
            // 添加
            if (--ct[s2[i] - 'a'] == 0) {
                if (--alpha_cnt == 0) {
                    return true;
                }
            }
            // 删除第一个
            if (++ct[s2[i - s1.size() + 1] - 'a'] == 1) {
                ++alpha_cnt;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "eidbaooo"\n
// @lcpr case=end

// @lcpr case=start
// "eidboaoo"\n
// @lcpr case=end

 */

