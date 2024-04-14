/*
 * @lc app=leetcode.cn id=62 lang=cpp
 * @lcpr version=30122
 *
 * [62] 不同路径
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
    int uniquePaths(int m, int n) {
        int start = m + n - 2;
        int t = min(m, n) - 1;
        long long fz = 1, fm = 1;
        for (int i = t; i >= 1; i--) {
            fz *= start--;
            fm *= i;
            if (fz % fm == 0) {
                fz /= fm;
                fm = 1;
            }
        }
        return fz / fm;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 7\n3\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

