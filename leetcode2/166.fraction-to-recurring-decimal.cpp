/*
 * @lc app=leetcode.cn id=166 lang=cpp
 * @lcpr version=30122
 *
 * [166] 分数到小数
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
    string fractionToDecimal(int numerator, int denominator) {
        int sign = (numerator >> 31 != denominator >> 31) ? -1 : 1;
        long long fz = numerator;
        long long fm = denominator;
        long long zd = fz / fm;
        string ans = to_string(zd);
        if (fz % fm == 0) {
            return ans;
        }
        if (sign == -1 and zd == 0) {
            ans.insert(0, "-");
        }
        ans.push_back('.');
        fz = abs(fz);
        fm = abs(fm);
        fz %= fm;
        int pos = ans.size();
        map<long long, int> memo;
        while (fz > 0 && !memo.count(fz)) {
            long long old = fz * 10;
            int v = old / fm;
            int left = old % fm;
            memo[fz] = pos++;
            ans.push_back(v + '0');
            fz = left;
        }
        if (fz == 0) {
            return ans;
        }
        ans.push_back(')');
        ans.insert(memo[fz], "(");
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 4\n333\n
// @lcpr case=end

 */

