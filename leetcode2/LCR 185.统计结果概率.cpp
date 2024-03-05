/*
 * @lc app=leetcode.cn id=LCR 185 lang=cpp
 * @lcpr version=30118
 *
 * [LCR 185] 统计结果概率
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
    // 逆向模拟
    vector<double> statisticsProbability(int num) {
        vector<double> tmp(6, 1.0 / 6);
        if (num == 1) {
            return tmp;
        }
        vector<double> dp(5 * num + 1);
        for (int i = 0; i < 6; i++) {
            dp[i] = 1.0 / 6;
        }
        for (int i = 2; i <= num; i++) {
            int pre = 6 * (i - 1) - 1;
            auto tp = dp;
            for (int j = 0; j < 5 * i + 1; j++) {
                tp[j] = 0;
                for (int p = max(0, j - 5); p <= min(pre, j); p++) {
                    tp[j] += dp[p] / 6;
                }
            }
            dp = tp;
        }
        return dp;
    }

    // 模拟，
    vector<double> statisticsProbability4(int num) {
        vector<double> tmp(6, 1.0 / 6);
        if (num == 1) {
            return tmp;
        }
        vector<double> dp(6 * num + 1);
        for (int i = 1; i <= 6; i++) {
            dp[i] = 1.0 / 6;
        }
        for (int i = 2; i <= num; i++) {
            int low = i, high = 6 * i, pre = 6 * (i - 1);
            auto tp = dp;
            for (int j = low; j <= high; j++) {
                tp[j] = 0;
                for (int p = max(j - 6, i - 1); p <= min(j - 1, pre); p++) {
                    tp[j] += dp[p] / 6;
                }
            }
            dp = tp;
        }
        vector<double> ans(5 * num + 1);
        for (int i = 0; i < 5 * num + 1; i++) {
            ans[i] = dp[i + num];
        }
        return ans;
    }

    vector<double> statisticsProbability2(int num) {
        vector<double> tmp(6, 1.0 / 6);
        if (num == 1) {
            return tmp;
        }
        int low = num, high = 6 * num, sz = high - num + 1;
        long long total = pow(6, num);
        vector<double> ans(sz);
        for (int t1 = 0; t1 <= num; t1++) {
            for (int t2 = 0; t2 <= num - t1; t2++) {
                for (int t3 = 0; t3 <= num - t1 -t2; t3++) {
                    for (int t4 = 0; t4 <= num - t1 - t2 - t3; t4++) {
                        for (int t5 = 0; t5 <= num - t1 -t2 -t3 -t4; t5++) {
                            int t6 = num - t1 - t2 -t3- t4 - t5;
                            int v = t1 * 1 + t2 * 2 + t3 * 3 + t4 * 4 + t5 * 5 + t6 * 6 - num;
                            ans[v] += (cnx(num, t1) * cnx(num - t1, t2) * cnx(num - t1 - t2, t3) * cnx(num - t1 - t2 - t3, t4) * cnx(num - t1 - t2 - t3 - t4, t5) * 1.0) / total;
                        }
                    }
                }
            }
        }
        return ans;
    }

    int cnx(int n, int t) {
        int fm = 1, fz = 1;
        for (int i = 0; i < t; i++) {
            fm *= (n - i);
            fz *= (i + 1);
            if (fm % fz == 0) {
                fm /= fz;
                fz = 1;
            }
        }
        return fm / fz;
    }

    // 枚举每个数字出现的次数
    vector<double> statisticsProbability3(int num) {
        vector<double> tmp(6, 1.0 / 6);
        if (num == 1) {
            return tmp;
        }
        int low = num, high = 6 * num, sz = high - num + 1;
        long long total = pow(6, num);
        vector<long long> times(sz);
        vector<double> ans(sz);
        for (int t1 = 0; t1 <= num; t1++) {
            for (int t2 = 0; t2 <= num - t1; t2++) {
                for (int t3 = 0; t3 <= num - t1 -t2; t3++) {
                    for (int t4 = 0; t4 <= num - t1 - t2 - t3; t4++) {
                        for (int t5 = 0; t5 <= num - t1 -t2 -t3 -t4; t5++) {
                            int t6 = num - t1 - t2 -t3- t4 - t5;
                            int v = t1 * 1 + t2 * 2 + t3 * 3 + t4 * 4 + t5 * 5 + t6 * 6 - num;
                            times[v] += cnx(num, t1) * cnx(num - t1, t2) * cnx(num - t1 - t2, t3) * cnx(num - t1 - t2 - t3, t4) * cnx(num - t1 - t2 - t3 - t4, t5);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < sz; i++) {
            ans[i] = times[i] * 1.0 / total;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

