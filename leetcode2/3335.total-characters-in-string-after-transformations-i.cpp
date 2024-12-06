/*
 * @lc app=leetcode.cn id=3335 lang=cpp
 * @lcpr version=30204
 *
 * [3335] 字符串转换后的长度 I
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
    // 关键是聚合
    int lengthAfterTransformations(string s, int t) {
        int ct[26]{};
        for (auto ch: s) {
            ct[ch - 'a']++;
        }
        int ans = 0;
        int mod = 1e9+7;
        for (int i = 0; i < t; i++) {
            int nct[26]{};
            for (int ch = 0; ch < 25; ch++) {
                if (ct[ch]) {
                    nct[ch + 1] = ct[ch];
                }
            }
            if (ct[25]) {
                nct[0] = (nct[0] +  ct[25]) % mod;
                nct[1] =  (nct[1] +  ct[25]) % mod;
            }
            for (int j = 0; j < 26; j++) {
                ct[j] = nct[j];
                if (i + 1 == t) {
                    ans = (ans + ct[j]) % mod;
                }
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcyy"\n2\n
// @lcpr case=end

// @lcpr case=start
// "azbk"\n1\n
// @lcpr case=end

 */

