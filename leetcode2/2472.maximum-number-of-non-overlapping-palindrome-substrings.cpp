/*
 * @lc app=leetcode.cn id=2472 lang=cpp
 * @lcpr version=30204
 *
 * [2472] 不重叠回文子字符串的最大数目
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
    int maxPalindromes1(string s, int k) {
        int n = s.size();
        // 单个的直接为1
        vector<vector<int>> isP(n, vector<int>(n, 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                isP[i][j] = (s[i] == s[j]) and isP[i + 1][j - 1];
            }
        }
        vector<int> f(n + 1);
        // abaccdbbd
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i];
            for (int j = i - k + 1; j >= 0; j--) {
                if (isP[j][i]) f[i + 1] = max(f[i + 1], f[j] + 1);
            }
        }
        return f[n];
    }

    int maxPalindromes2(string s, int k) {
        int n = s.length(), f[n + 1];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = l + i % 2; // 中心扩展法
            f[l + 1] = max(f[l + 1], f[l]);
            for (; l >= 0 && r < n && s[l] == s[r]; --l, ++r)
                if (r - l + 1 >= k) {
                    f[r + 1] = max(f[r + 1], f[l] + 1);
                    break;
                }
        }
        return f[n];
    }
    
    // 马拉车
};
// @lc code=end



/*
// @lcpr case=start
// "abaccdbbd"\n3\n
// @lcpr case=end

// @lcpr case=start
// "adbcda"\n2\n
// @lcpr case=end

 */

