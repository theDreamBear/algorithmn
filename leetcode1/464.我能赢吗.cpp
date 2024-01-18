/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

// @lc code=start
class Solution1 {
public:
    bool canWin(int maxChoosableInteger, unordered_map<int, bool>& mp, int now, int mask, int desiredTotal) {
        if (now >= desiredTotal) {
            return true;
        }
        int code = mask * 301 + now;
        if (mp.count(code)) {
            return mp[code];
        }
        bool flag = false;
        for (int i = 0; i < maxChoosableInteger; i++) {
            // 已选择
            if (mask & (0x1 << i)) {
                continue;
            }
            // 当前可赢
            if (now + i + 1 >= desiredTotal) {
                flag = true;
                break;
            }
            if (!canWin(maxChoosableInteger, mp, now + (i + 1), mask ^ (0x1 << i), desiredTotal)) {
                flag = true;
                break;
            }
        }
        return mp[code] = flag;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * maxChoosableInteger + maxChoosableInteger < desiredTotal * 2) {
            return false;
        }
        unordered_map<int, bool> mp;
        return canWin(maxChoosableInteger, mp, 0, 0, desiredTotal);
    }
};

class Solution2 {
public:
    bool canWin(int maxChoosableInteger, vector<bool> &dp, int now, int mask, int desiredTotal) {
        if (now >= desiredTotal) {
            return true;
        }
        if (dp[mask]) {
            return dp[mask];
        }
        bool flag = false;
        for (int i = 0; i < maxChoosableInteger; i++) {
            // 已选择
            if (mask & (0x1 << i)) {
                continue;
            }
            // 当前可赢
            if (now + i + 1 >= desiredTotal) {
                flag = true;
                break;
            }
            if (!canWin(maxChoosableInteger, dp, now + (i + 1), mask ^ (0x1 << i), desiredTotal)) {
                flag = true;
                break;
            }
        }
        return dp[mask] = flag;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * maxChoosableInteger + maxChoosableInteger < desiredTotal * 2) {
            return false;
        }
        int n = 1 << maxChoosableInteger;
        vector<bool> dp(n);
        return canWin(maxChoosableInteger, dp, 0, 0, desiredTotal);
    }
};

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger * maxChoosableInteger + maxChoosableInteger < desiredTotal * 2) {
            return false;
        }
        int n = (1 << maxChoosableInteger);
        vector<bool> dp(n);
        vector<int> sum(n);
        dp[0] = false;
        sum[0] = 0;
        // 如果为true， 直接跳过
        // 如果有一个前为true 则为false
        //
        for (int i = 1; i < n; i++) {
            int j = i;
            bool flag = false;
            while (j > 0) {
                int p = __builtin_ctz(j);
                j ^= (1 << p);
                int next = i ^ (1 << p);
                if (sum[i] == 0) {
                    sum[i] = sum[next] + p + 1;
                }
                flag |= dp[next];
            }
            dp[i] = !flag;
            if (sum[i] == desiredTotal && dp[i]) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

