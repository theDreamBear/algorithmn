/*
 * @lc app=leetcode.cn id=LCR 161 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 161] 连续天数的最高销售额
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
    /*
        贪心的解法
        ans 取最大的一段的值
        sum = [left, i) 之和
        if (sum <= 0) {
            1. 这一段就是最大值
            对于这种情况, 我们已经求过了, 接着处理下一个连续段
            2. 这一段不包含在最大值之列
            我们继续求下一个连续段
        }
        
    */
    int maxSales(vector<int>& sales) {
        int ans = sales[0];
        int sum = sales[0];
        for (int i = 1; i < sales.size(); i++) {
            if (sum <= 0) {
                sum = sales[i];
            } else {
                sum += sales[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

