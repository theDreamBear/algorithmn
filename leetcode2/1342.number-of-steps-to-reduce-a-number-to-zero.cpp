/*
 * @lc app=leetcode.cn id=1342 lang=cpp
 * @lcpr version=30204
 *
 * [1342] 将数字变成 0 的操作次数
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
    int numberOfSteps(int num) {
        if (num == 0) return 0;
        return 1 + (num % 2 == 0 ? numberOfSteps(num / 2) : numberOfSteps(num - 1));
    }
};
// @lc code=end



/*
// @lcpr case=start
// 14\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

// @lcpr case=start
// 123\n
// @lcpr case=end

 */

