/*
 * @lc app=leetcode.cn id=2154 lang=cpp
 * @lcpr version=30204
 *
 * [2154] 将找到的值乘以 2
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
    int findFinalValue1(vector<int>& nums, int original) {
        int cnt[3000]{};
        for (auto v: nums) {
            cnt[v] = 1;
        }
        while (cnt[original]) {
            original <<= 1;
        }
        return original;
    }

    int findFinalValue(vector<int>& nums, int original) {
        int mask = 0;
        for (auto v: nums) {
            if (v % original == 0) {
                int x = v / original;
                if ((x & (x - 1)) == 0) {
                    mask |= x;
                }
            }
        }
        if ((mask & 1) == 0) return original;
        int lb = mask & (-mask);
        //return original << (__builtin_ctz((mask + lb) & ~mask));
        return original * ((mask + lb) & ~mask);
    }

    int findFinalValue2(vector<int>& nums, int original) {
        int mask = 0;
        for (auto v: nums) {
            if (v % original == 0) {
                int x = v / original;
                if ((x & (x - 1)) == 0) {
                    mask |= x;
                }
            }
        }
        mask = ~mask;
        return original * (mask & -mask);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,3,6,1,12]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9]\n4\n
// @lcpr case=end

 */

