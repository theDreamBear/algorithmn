/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
constexpr int MAX_N = 20;

signed char dp[1 << MAX_N][300];
int max_state;
int max_choosable_integer;

class Solution {
public:
    int canIWinHelper(int state, int left) {
        if (dp[state][left] != 0) {
            return dp[state][left];
        }
        int cur = state;
        for (int i = max_choosable_integer - 1;i >= 0; i--) {
            if (!(state & (1 << i))) {
                continue;
            }
            if (i + 1 >= left) {
                return dp[state][left] = 1;
            }
            if (canIWinHelper(state ^ (1 << i), left - i - 1) == -1) {
                return dp[state][left] = 1;
            }
        }
        return dp[state][left] = -1;
    }

    /*
     *  状态1. 还可选的值
     *  状态2. 还剩的和
     *  可选状态用 20位表示 state 2^20 种, 剩余 300
     *  时间复杂度 2^20 * 300 = 3 * 10^8 勉强能通过
     * */
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        max_choosable_integer = maxChoosableInteger;
        max_state = (1 << maxChoosableInteger) - 1;
        int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal) {
            return false;
        }
        if (canIWinHelper(max_state, desiredTotal) == 1) {
            return true;
        }
        return false;
    }
};
// @lc code=end

