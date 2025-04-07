/*
 * @lc app=leetcode.cn id=2595 lang=cpp
 * @lcpr version=30204
 *
 * [2595] 奇偶位数
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
    vector<int> evenOddBit1(int n) {
        int e = 0, o = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                e += i % 2 == 0;
                o += i % 2 == 1;
            }
        }
        return {e, o};
    }

    vector<int> evenOddBit(int n) {
        int e = __builtin_popcount(n & 0x5555);
        int o = __builtin_popcount(n & 0xaaaa);
        return {e, o};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 50\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */

