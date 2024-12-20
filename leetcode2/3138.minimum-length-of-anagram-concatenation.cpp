/*
 * @lc app=leetcode.cn id=3138 lang=cpp
 * @lcpr version=30204
 *
 * [3138] 同位字符串连接的最小长度
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
    int minAnagramLength(string s) {
        int n = s.size();
        if (n == 1) return 1;
        // 所有公约数
        auto getDivisor = [&](int val) {
            vector<int> divs;
            for (int i = 1; i * i <= val; i++) {
                if (val % i == 0) {
                    divs.push_back(i);
                    if (i * i != val or i != 1) {
                        divs.push_back(val / i);
                    }
                }
            }
            return divs;
        };
        auto divs = getDivisor(n);
        ranges::sort(divs);
        for (auto d: divs) {
            int cnt[26]{};
            for (int i = 0; i < d; i++) {
                cnt[s[i] - 'a']++;
            }
            auto check = [&](int step) {
                bool ok = true;
                int start = step;
                while (start < n and ok) {
                    int ct[26]{};
                    for (int i = 0; i < step; i++) {
                        ct[s[i + start] - 'a']++;
                    }
                    start += step;
                    for (int i = 0; i < 26; i++) {
                        if (cnt[i] != ct[i]) {
                            ok = false;
                            break;
                        }
                    }
                }
                return ok;
            };
            if (check(d)) {
                return d;
            }
        }
        return n;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n
// @lcpr case=end

// @lcpr case=start
// "cdef"\n
// @lcpr case=end

 */

