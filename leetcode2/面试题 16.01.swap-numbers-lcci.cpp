/*
 * @lc app=leetcode.cn id=面试题 16.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.01] 交换数字
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
    vector<int> swapNumbers(vector<int>& vals) {
        vals[0] ^= vals[1] ^= vals[0] ^= vals[1];
        return vals;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

