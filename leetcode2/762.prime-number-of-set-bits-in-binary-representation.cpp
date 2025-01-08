/*
 * @lc app=leetcode.cn id=762 lang=cpp
 * @lcpr version=30204
 *
 * [762] 二进制表示中质数个计算置位
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
    int countPrimeSetBits1(int left, int right) {
        int isPrim[33]{};
        //isPrim[2] = isPrim[3] = 1;
        for (int i = 2; i <= 32; i++) {
            bool isP = true;
            for (int x = 2; x * x <= i; x++) {
                if (i % x == 0) {
                    isP = false;
                    break;
                }
            }
            isPrim[i] = isP;
        }
        int ans = 0;
        for (int i = left; i <= right; i++) {
            if (isPrim[__builtin_popcount(i)]) ans++;
        }
        return ans;
    }

    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int x = left; x <= right; ++x) {
            if ((1 << __builtin_popcount(x)) & 665772) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 6\n10\n
// @lcpr case=end

// @lcpr case=start
// 10\n15\n
// @lcpr case=end

 */

