/*
 * @lc app=leetcode.cn id=2412 lang=cpp
 * @lcpr version=30204
 *
 * [2412] 完成所有交易的初始最少钱数
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
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<vector<int>> a;
        long long r1 = 0, r2 = 0;
        for (auto& vec: transactions) {
            r1 = max(r1, (long long)vec[0]);
            if (vec[0] - vec[1] > 0) {
                a.emplace_back(move(vec));
            } else {
                r2 = max(r2, (long long) vec[0]);
            }
        }
        ranges::sort(a, {}, [&](auto& x) {
            return x[1];
        });
        long long mx = 0, cur = 0, mx2 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (i + 1 ==  a.size()) {
                mx2 = cur + a[i][0];
            }
            cur += (a[i][0] - a[i][1]);
            mx = max(mx, cur);
        }
        return max({r1, cur + r2, mx2});
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1],[5,0],[4,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,0],[0,3]]\n
// @lcpr case=end

 */

