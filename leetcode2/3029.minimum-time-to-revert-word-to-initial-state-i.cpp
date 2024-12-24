/*
 * @lc app=leetcode.cn id=3029 lang=cpp
 * @lcpr version=30204
 *
 * [3029] 将单词恢复初始状态所需的最短时间 I
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
    // 暴力 o(n ^ 2)
    int minimumTimeToInitialState1(string word, int k) {
        int n = word.size();
        int t = 1;
        for (; t * k < n; t++) {
            bool ok = true;
            int p = t * k;
            for (int x = 0; p + x < n; x++) {
                if (word[p + x] != word[x]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return t;
            }
        }
        return t;
    }

    // 忘记z函数了, 尝试推导
    // z[i] 表示s[0,..., n - 1] 和s[i, ... n - 1] 的最大前缀
    // [left, right]
    int minimumTimeToInitialState(string word, int k) {
        // 似乎和前后缀长度有关
        // z 函数
        //string st = word + "#" + word;
        int n = word.size();
        vector<int> z(n);
        z[0] = n;
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n and word[z[i]] == word[i + z[i]]) z[i]++;
            if (i + z[i] > r) {
                r = i + z[i] - 1;
                l = i;
            }
        }
        int t = 1;
        int m = word.size();
        for (; t * k < m; t++) {
            bool ok = true;
            int p = t * k;
            if (z[p] >= m - p) {
                return t;
            }
        }
        return t;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abacaba"\n3\n
// @lcpr case=end

// @lcpr case=start
// "abacaba"\n4\n
// @lcpr case=end

// @lcpr case=start
// "abcbabcd"\n2\n
// @lcpr case=end

 */
