/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (31.42%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    37.9K
 * Total Submissions: 120.1K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        // 暴力算出所有
        #ifdef VIALIATE
        if (n < 2) {
            return 0;
        }
        int ct = 0;
        for(int i  = 2; i < n; ++i) {
            bool yes = true;
            for(int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    yes = false;
                    break;
                }
            }
            if (yes) {
                //cout << i << endl;
                ++ct;
            }

        }
        return ct;
        #endif // VIALIATE
        
        // 埃氏筛选法
        if (n <= 2) {
            return 0;
        }
        int ah[n];
        memset(ah, 0, sizeof(int) * n);
        ah[2] = 1;
        int ct = n - 2;

        int up = sqrt(n);
        if (up * up == n) {
            --up;
        }
        for (int m = 2; m <= up; ++m) {
            int i = m * m;
            if (ah[i] != 0) {
                continue;
            }
            for(; i < n ; i += m) {
                if (ah[i] == 0) {
                    --ct;
                    ah[i] = 1;
                }
            }
        }
        return ct;
    }
};
// @lc code=end

