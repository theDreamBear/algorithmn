/*
 * @lc app=leetcode.cn id=面试题 16.05 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.05] 阶乘尾数
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
    int trailingZeroes(int n) {
        // 5 25 125
        int ans = 0;
        while (n) {
            ans += n / 5;
            n /= 5;
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

