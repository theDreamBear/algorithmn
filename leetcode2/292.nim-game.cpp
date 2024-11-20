/*
 * @lc app=leetcode.cn id=292 lang=cpp
 * @lcpr version=30204
 *
 * [292] Nim 游戏
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
    vector<int> calG(int n, vector<int> candidate) {
        ranges::sort(candidate);
        vector<int> g(n + 1), s(n + 2);
        for (int i = 1; i <= n; i++) {
            fill(s.begin(), s.end(), 0);
            for (int j = 0; j < candidate.size() and candidate[j] <= i; j++) {
                s[g[i - candidate[j]]] = 1;
            }
            int res = 0;
            while (s[res]) res++;
            g[i] = res;
        }
        return g;
    }

    // n 太大了
    bool canWinNim_g(int n) {
        auto g = calG(n, {1, 2, 3});
        return g[n] != 0;
    }

    bool canWinNim(int n) {
        return n % 4 == 0 ? false: true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

