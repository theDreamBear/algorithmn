/*
 * @lc app=leetcode.cn id=645 lang=cpp
 * @lcpr version=30204
 *
 * [645] 错误的集合
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
    vector<int> findErrorNums1(vector<int>& nums) {
        // 
        int n = nums.size();
        int left = (n + 1) % 4;
        int val = (n + 1) / 4 * 4;
        int x = 0;
        for (int i = 0; i < left; i++) {
            x ^= (val + i);
        }
        for (auto v: nums) {
            x ^= v;
        }
        int lb = x & (-x);
        int x1 = 0, x2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i & lb) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        for (auto v: nums) {
            if (v & lb) {
                x1 ^= v;
            } else {
                x2 ^= v;
            }
        }
        for (auto v: nums) {
            if (v == x1) {
                return {x1, x2};
            } else if (v == x2) {
                return {x2, x1};
            }
        }
        return {x1, x2};
    }

    vector<int> findErrorNums(vector<int>& nums) {
        // 
        int n = nums.size();
        long long s1 = (1 + n) * n / 2;
        long long s12 = (long long)(2 * n + 1) * n * (n + 1) / 6;

        long long s2 = 0, s22 = 0;
        for (long long v: nums) {
            s2 += v;
            s22 += v * v;
        }
        return vector<int>{(int)(s2 - s1 + (s22 - s12) / (s2 - s1)) / 2, (int)(s1 - s2 + (s2 - s1 + (s22 - s12) / (s2 - s1)) / 2)};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1]\n
// @lcpr case=end

 */

