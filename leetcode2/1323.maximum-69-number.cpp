/*
 * @lc app=leetcode.cn id=1323 lang=cpp
 * @lcpr version=30204
 *
 * [1323] 6 和 9 组成的最大数字
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
    int maximum69Number (int num) {
        auto x = to_string(num);
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '6') {
                x[i] = '9';
                break;
            }
        }
        return atoi(x.c_str());
    }
};
// @lc code=end



/*
// @lcpr case=start
// 9669\n
// @lcpr case=end

// @lcpr case=start
// 9996\n
// @lcpr case=end

// @lcpr case=start
// 9999\n
// @lcpr case=end

 */

