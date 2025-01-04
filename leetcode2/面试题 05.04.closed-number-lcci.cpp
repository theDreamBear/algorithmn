// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=面试题 05.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.04] 下一个数
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
    // 正整数
    vector<int> findClosedNumbers1(int num) {
        int left = -1, right = -1;
        // 从低到高找到第一个0
        // 从将更高位置的一个1交换过来就是left
        int zeroPos = -1, onePos = -1;
        int onecnt = 0;
        for (int i = 0; i < 31; i++) {
            if (num >> i & 1) {
                onecnt++;
                if (zeroPos != -1) {
                    left = num ^ (1 << i);
                    left &= (0xffffffff >> zeroPos << zeroPos);
                    for (int x = 0; x < onecnt; x++) {
                        left |= (1 << (zeroPos - x));
                    }
                    break;
                }
            } else {
                zeroPos = i;
            }
        }
        zeroPos = -1, onePos = -1;
        onecnt = 0;
        for (int i = 0; i < 31; i++) {
            if (num >> i & 1) {
                onePos = i;
                onecnt++;
            } else {
                if (onePos != -1) {
                    right = num ^ (1 << i);
                    right &= (0xffffffff >> i << i);
                    for (int x = 0; x + 1 < onecnt; x++) {
                        right |= (1 << x);
                    }
                    break;
                }
            }
        }
        // 从低到高找到第一个0且其低位有1, 将这个1交换过来就是right
        return {right, left};
    }

    // 再思考下
    // 好像更恶心纯位操作代码



    vector<int> findClosedNumbers2(int num) {
        int left = -1, right = -1;
        // left 找到第一个10
        if (num != INT_MAX and num != 1) {
            if (num & 1) {
                int y = (num + 1);
                int z = y & (-y);
                y -= z;
                int x = y & (-y);
                int s2 = __builtin_popcount((x - 1) & num);
                int sub = (__builtin_ctz(x) - s2 - 1);
                left =  (~(x - 1) & num) ^ ((x - 1) >> sub << sub) ^ x;
            } else {
                // 偶数
                // 最右1
                int x = num & (-num);
                left = num ^ x ^ (x >> 1);
            }
        }
        // right 找到第一个01
        if (num < INT_MAX - 1) {
            if (num & 1) {
                // 奇数
                int y = (num + 1) & ~num;
                right = num ^ y ^ (y >> 1);
            } else {
                int x = num & (-num);
                int z = num ^ (x - 1);
                int y = (z + 1) & (-z);
                int sub = (y - 1) & num;
                int add = (1 << (__builtin_popcount((y - 1) & num)) - 1) - 1;
                right = num ^ sub ^ y ^ add;
            }
        }
        return {right, left};
    }

    int f(int v) {
        int lb = v & (-v);
        int r = lb + v;
        return r | (v ^ r) / lb >> 2;
    }

    vector<int> findClosedNumbers(int num) {
        if (num == INT_MAX) return {-1, -1};
        if (num == 1) {
            return {2, -1};
        }
        vector<int> ans{-1, -1};
        return {f(num), ~f(~num)};
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findClosedNumbers
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 2（或者0b10）\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

