/*
 * @lc app=leetcode.cn id=LCR 177 lang=cpp
 * @lcpr version=30117
 *
 * [LCR 177] 撞色搭配
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
    vector<int> sockCollocation(const vector<int>& sockets) {
        int value = 0;
        for (auto v : sockets) {
            value ^= v;
        }
        int left = 0;
        int right = 0;
        int pos = __builtin_ffs(value) - 1;
        for (auto v : sockets) {
            if (v & 1 << pos) {
                left ^= v;
            } else {
                right ^= v;
            }
        }
        return {left, right};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4, 5, 2, 4, 6, 6]\n
// @lcpr case=end

// @lcpr case=start
// [1, 2, 4, 1, 4, 3, 12, 3]\n
// @lcpr case=end

 */

