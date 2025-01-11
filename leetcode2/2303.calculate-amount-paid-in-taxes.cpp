/*
 * @lc app=leetcode.cn id=2303 lang=cpp
 * @lcpr version=30204
 *
 * [2303] 计算应缴税款总额
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
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int pre = 0;
        for (auto& vec: brackets) {
            int upper = vec[0], per = vec[1];
            if (income >= pre) {
                ans += (min(upper, income) - pre) * per / 100.0;
                pre = upper;
            } else {
                break;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,50],[7,10],[12,25]]\n10\n
// @lcpr case=end

// @lcpr case=start
// [[1,0],[4,25],[5,50]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[2,50]]\n0\n
// @lcpr case=end

 */

