/*
 * @lc app=leetcode.cn id=326 lang=cpp
 * @lcpr version=30204
 *
 * [326] 3 的幂
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
    bool isPowerOfThree1(int n) {
        while (n and n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    bool isPowerOfThree(int n) {
        return n > 0 and  1162261467 % n == 0;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 27\n
// @lcpr case=end

// @lcpr case=start
// 0\n
// @lcpr case=end

// @lcpr case=start
// 9\n
// @lcpr case=end

// @lcpr case=start
// 45\n
// @lcpr case=end

 */

