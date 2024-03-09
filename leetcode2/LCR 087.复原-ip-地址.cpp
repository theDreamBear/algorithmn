/*
 * @lc app=leetcode.cn id=LCR 087 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 087] 复原 IP 地址
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
    void backtrack(vector<string>& ans, const string& s, string tmp, int num, int pos) {
        if (pos >= s.size() || num >= 4) {
            if (num == 4 && pos == s.size()) {
                ans.push_back(tmp);
            }
            return;
        }
         // 处理前导0
        if (s[pos] == '0') {
            if (num != 0) {
                tmp.push_back('.');
            }
            tmp.push_back('0');
            backtrack(ans, s, tmp, num + 1, pos + 1);
            return;
        }
        int val = 0;
        for (int i = 0; i < 3; i++) {
            val = 10 * val + (s[i + pos] - '0');
            if (val >= 0 and val <= 255) {
                string cur = tmp;
                if (num != 0) {
                    cur.push_back('.');
                }
                cur += to_string(val);
                backtrack(ans, s, cur, num + 1, pos + i + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.size() < 4 || s.size() > 12) {
            return ans;
        }
        backtrack(ans, s, "", 0, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "1111"\n
// @lcpr case=end

// @lcpr case=start
// "010010"\n
// @lcpr case=end

// @lcpr case=start
// "10203040"\n
// @lcpr case=end

 */

