/*
 * @lc app=leetcode.cn id=1137 lang=cpp
 * @lcpr version=30204
 *
 * [1137] 第 N 个泰波那契数
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
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int f0 = 0, f1 = 1, f2 = 1;
        for (int i = 3; i <= n; i++) {
            int x = f0 + f1 + f2;
            f0 = f1;
            f1 = f2;
            f2 = x;
        }
        return f2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 25\n
// @lcpr case=end

 */

