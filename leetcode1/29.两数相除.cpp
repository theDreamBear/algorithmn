/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include<cmath>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 问题1  (long long)dividend
        long long ldd = abs((long long)dividend);
        long long ldr = abs((long long)divisor);
        if (ldd < ldr) {
            return 0;
        }
        int sign = 1;
        int ls = (dividend >> 31) & 0x1;
        int rs = (divisor >> 31) & 0x1;
        if ((ls ^ rs) != 0) {
            sign = -1;
        }
        // 问题2 类型是long long
        vector<long long> temp;
        long long start = ldr;
        while (start <= ldd) {
            temp.push_back(start);
            start <<= 1;
        }
        start >>= 1;
        long long ans = 0;
        if (start != ldd) {
            while (ldd >= ldr) {
                auto it = upper_bound(temp.begin(), temp.end(), ldd);
                int offset = 0;
                if (it == temp.end()) {
                    offset = temp.size() - 1;
                } else {
                    offset = it - temp.begin() - 1;
                }
                ldd -= temp[offset];
                ans += (1 << offset);
            }
        } else {
            // 问题3 1ll
            // 问题4 (temp.size() - 1) 外面的括号
            ans = (1ll << (temp.size() - 1)); 
        }
        if (sign == 1) {
            if (ans >= (long long)INT32_MAX) {
                return INT32_MAX;
            }
            return ans;
        } else {
            if (ans <= (long long)INT32_MIN) {
                return INT32_MIN;
            }
            // 问题6 正数转化成负数的逻辑
            return ~(ans - 1);
            return ~ans + 1;
        }
    }
};
// @lc code=end

