
/*
 * @lc app=leetcode.cn id=2550 lang=cpp
 * @lcpr version=30204
 *
 * [2550] 猴子碰撞的方法数
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
    int monkeyMove(int n) {
        int mod = 1e9 + 7;
        auto fast = [&](long long exp) {
            long long res = 1;
            long long base = 2;
            while (exp) {
                if (exp & 1) res = res * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return res;
        };
        return (fast(n) - 2 + mod) % mod;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */

