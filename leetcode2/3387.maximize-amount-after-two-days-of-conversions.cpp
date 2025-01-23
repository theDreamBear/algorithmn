/*
 * @lc app=leetcode.cn id=3387 lang=cpp
 * @lcpr version=30204
 *
 * [3387] 两天自由外汇交易后的最大货币数
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
#include <map>
#include <set>
#include <string>
#include <string.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, double> cnt;
        cnt[initialCurrency] = 1;
        for (int i = 0; i < pairs1.size(); i++) {
            string st = pairs1[i][0], ta = pairs1[1][1];
            double rate = rates1[i];
            cnt[ta] = max(cnt[ta], cnt[st] * rate);
        }
        for (int i = 0; i < pairs2.size(); i++) {
            string st = pairs2[i][0], ta = pairs2[1][1];
            double rate = rates2[i];
            cnt[ta] = max(cnt[ta], cnt[st] * rate);
        }
        return cnt[initialCurrency];
    }
};
// @lc code=end



/*
// @lcpr case=start
// "EUR"\n[["EUR","USD"],["USD","JPY"]]\n[2.0,3.0]\n[["JPY","USD"],["USD","CHF"],["CHF","EUR"]]\n[4.0,5.0,6.0]\n
// @lcpr case=end

// @lcpr case=start
// "NGN"\n[["NGN","EUR"]]\n[9.0]\n[["NGN","EUR"]]\n[6.0]\n
// @lcpr case=end

// @lcpr case=start
// "USD"\n[["USD","EUR"]]\n[1.0]\n[["EUR","JPY"]]\n[10.0]\n
// @lcpr case=end

 */

