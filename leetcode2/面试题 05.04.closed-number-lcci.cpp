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
    vector<int> findClosedNumbers(int num) {
        int left = -1, right = -1;
        // left 找到第一个10

        // right 找到第一个01
        int zeroPos = -1, onePos = -1;

        return {right, left};
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2（或者0b10）\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

