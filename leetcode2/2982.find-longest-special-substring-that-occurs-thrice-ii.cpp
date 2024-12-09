/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=30204
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
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
    int maximumLength1(string s) {
        int ans = 0;
        // xiao zhong da
        int cnt[26][3]{};
        int n = s.size();
        // 分组循环
        for (int i = 0; i < n;) {
            int start = i++;
            while (i < n and s[i] == s[start]) i++;
            int len = i - start;
            int idx = s[start] - 'a';
            int ct[6]{};
            ct[0] = cnt[idx][0];
            ct[1] = cnt[idx][1];
            ct[2] = cnt[idx][2];
            ct[3] = len;
            ct[4] = max(0, len - 1);
            ct[5] = max(0, len - 2);
            sort(ct, ct + 6, greater<>{});

            cnt[idx][0] = ct[0];
            cnt[idx][1] = ct[1];
            cnt[idx][2] = ct[2];
            ans = max(ans, ct[2]);
        }
        return ans == 0 ? -1 : ans;
    }

    int maximumLength(string s) {
        int ans = 0;
        // xiao zhong da
        int cnt[26][3]{};
        int n = s.size();
        auto update = [&](auto&& update, int idx, int i, int v) {
            if (v <= 0) return;
            if (i >= 3) return;
            if (v > cnt[idx][i]) {
                update(update, idx, i + 1, cnt[idx][i]);
                cnt[idx][i] = v;
            } else {
                update(update, idx, i + 1, v);
            }
        };
        // 分组循环
        for (int i = 0; i < n;) {
            int start = i++;
            while (i < n and s[i] == s[start]) i++;
            int len = i - start;
            int idx = s[start] - 'a';
            update(update, idx, 0, len);
            update(update, idx, 1, len - 1);
            update(update, idx, 2, len - 2);
            ans = max(ans, cnt[idx][2]);
        }
        return ans == 0 ? -1 : ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

