/*
 * @lc app=leetcode.cn id=面试题 05.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.01] 插入
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
    int insertBits1(int N, int M, int i, int j) {
        auto getBin = [](int val) {
            string res;
            while (val) {
                res.push_back((val & 1) + '0');
                val >>= 1;
            }
            ranges::reverse(res);
            return res;
        };
        auto si = getBin(N), sj = getBin(M);
        // 补齐
        if (si.size() < j + 1) {
            si = string(j + 1 - si.size(), '0') + si;
        }
        for (int x = si.size() - i - 1, y = sj.size() - 1; x >= (int)si.size() - j - 1; x--) {
            char ch = y >= 0 ? sj[y]: '0';
            si[x] = ch;
            y--;
        }
        int ans = 0;
        int p = 0;
        for (int x = si.size() - 1; x >= 0; x--, p++) {
            ans += (si[x] - '0') * (1 << p);
        }
        return ans;
    }

    int insertBits2(int N, int M, int i, int j) {
        for (int x = i; x <= j; x++) {
            N &= ~(1 << x);
        }
        return N | (M << i);
    }

    int insertBits3(int N, int M, int i, int j) {
        unsigned int mask = 0xffffffff;
        mask <<= (31 - j);
        mask >>= (31 - j);
        mask >>= i;
        mask <<= i;
        N &= ~mask;
        return N | (M << i);
    }

    int insertBits(int N, int M, int i, int j) {
        return (N & ~((0xffffffff >> (31 - j + i)) << i)) ^ (M << i);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1024(10000000000)\n19(10011)\n2\n6\n
// @lcpr case=end

// @lcpr case=start
// 0\n31(11111)\n0\n4\n
// @lcpr case=end

 */

