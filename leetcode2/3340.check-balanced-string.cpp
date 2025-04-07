/*
 * @lc app=leetcode.cn id=3340 lang=cpp
 * @lcpr version=30204
 *
 * [3340] 检查平衡字符串
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
    bool isBalanced(string num) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            if (i % 2 == 0) {
                sum += (num[i] - '0');
            } else {
                sum -= (num[i] - '0');
            }
        }
        return sum == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "1234"\n
// @lcpr case=end

// @lcpr case=start
// "24123"\n
// @lcpr case=end

 */

