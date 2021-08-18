/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
static constexpr int MAX_N = 20;

class Solution {
 public:
    signed char dp[1 << MAX_N];
    unsigned int max_state;
    int max_choosable_integer;

    int max_left(unsigned int state) { return 32 - __builtin_clz(state); }

    int canIWinHelper(unsigned int state, int left) {
        if (dp[state] != 0) {
            return dp[state];
        }
        if (max_left(state) >= left) {
            return dp[state] = 1;
        }
#ifdef VI
        for (int i = max_choosable_integer - 1; i >= 0; i--) {
            if (!(state & (1 << i))) {
                continue;
            }
            if (canIWinHelper(state ^ (1 << i), left - i - 1) == -1) {
                return dp[state][left] = 1;
            }
        }
#else  // 加速
        int cur = state;
        while (cur) {
            int rank = max_left(cur);
            int val = (1 << (rank - 1));
            cur ^= val;
            if (canIWinHelper(state ^ val, left - rank) == -1) {
                return dp[state] = 1;
            }
        }
#endif
        return dp[state] = -1;
    }

    /*
     *  状态1. 还可选的值
     *  状态2. 还剩的和
     *  可选状态用 20位表示 state 2^20 种, 剩余 300
     *  时间复杂度 2^20 * 300 = 3 * 10^8 勉强能通过
     * */
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        max_choosable_integer = maxChoosableInteger;
        int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) {
            return false;
        }
        max_state = (1 << maxChoosableInteger) - 1;
        if (canIWinHelper(max_state, desiredTotal) == 1) {
            return true;
        }
        return false;
    }
};
// @lc code=end

int main() { cout << Solution{}.canIWin(10, 1) << endl; }
