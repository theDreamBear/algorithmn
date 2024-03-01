/*
 * @lc app=leetcode.cn id=LCR 165 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 165] 解密数字
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
    /*
        现有一串神秘的密文 ciphertext，经调查，密文的特点和规则如下：
        密文由非负整数组成
        数字 0-25 分别对应字母 a-z
        请根据上述规则将密文 ciphertext 解密为字母，并返回共有多少种解密结果。
        多少种? dp
    */


    /*
        定义： dp[i] 前i个的次数
        状态转移方程： dp[i] = dp[i - 1] + v <= 25 ? dp[i - 2]: 0;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1 + 21 ? dp[0] : 0 = 2
        dp[3] = dp[2] + 16 ? dp[1] : 0 = 3;
        dp[4] = dp[3] + 66 ? d[2] : 0 = 3;
        dp[5] = dp[4] + 61 ? dp[3] : 0 = 3;
        dp[6] = dp[5] + 12 ? dp[4] : 0 = 6;

    */
    int crackNumber(int ciphertext) {
        auto text = to_string(ciphertext);
        int n = text.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i + 1] = dp[i];
            int v = (text[i - 1] - '0') * 10 + (text[i] - '0');
            // 前导0也是异常情况
            if (text[i - 1] - '0' != 0 and v <= 25) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp.back();
    }
};
// @lc code=end



/*
// @lcpr case=start
// 216612\n
// @lcpr case=end

 */

