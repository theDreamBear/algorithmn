/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 * @lcpr version=30122
 *
 * [2320] 统计放置房子的方式数
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
    int countHousePlacements(int n) {
        int MOD = 1e9 + 7;
        long long prepre = 1;
        long long pre = 2;
        for (int i = 2; i <= n; i++) {
            long long tmp = prepre + pre;
            prepre = pre;
            pre = tmp;
            if (pre >= MOD) {
                pre %= MOD;
            }
        }
        return (pre * pre) % MOD;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

