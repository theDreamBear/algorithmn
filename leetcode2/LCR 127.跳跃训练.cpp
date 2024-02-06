/*
 * @lc app=leetcode.cn id=LCR 127 lang=cpp
 * @lcpr version=30116
 *
 * [LCR 127] 跳跃训练
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
    int trainWays(int num) {
        if (num <= 1) {
            return 1;
        }
        int pp = 1, p = 1;
        int ct = 1;
        while (ct++ < num) {
            int tmp = p;
            p += pp;
            pp = tmp;
            p %= (int)(1e9 + 7);
        }
        return p;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 5\n
// @lcpr case=end

 */

