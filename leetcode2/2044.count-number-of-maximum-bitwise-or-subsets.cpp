/*
 * @lc app=leetcode.cn id=2044 lang=cpp
 * @lcpr version=30204
 *
 * [2044] 统计按位或能得到最大值的子集数目
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
#include <bits/stdc++.h>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ma = reduce(nums.begin(), nums.end(), 0, [](int a, int b) {
            return a | b;
        });
        int ans = 0;
        auto dfs = [&](auto&& dfs, int i, int v) {
            if (i >= nums.size()) {
                if (v == ma) {
                    ans++;
                }
                return;
            }
            dfs(dfs, i + 1, v);
            dfs(dfs, i + 1, v | nums[i]);
        };
        dfs(dfs, 0, 0);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,5]\n
// @lcpr case=end

 */

