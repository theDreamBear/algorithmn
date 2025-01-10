/*
 * @lc app=leetcode.cn id=509 lang=cpp
 * @lcpr version=30204
 *
 * [509] 斐波那契数
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
    int fib(int n) {
        if (n <= 1) return n;
        int prpre = 0, pre = 1;
        for (int i = 2; i <= n; i++) {
            int x = prpre + pre;
            prpre = pre;
            pre = x;
        }
        return pre;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

