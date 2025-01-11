/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 * @lcpr version=30204
 *
 * [1331] 数组序号转换
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
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rk = arr;
        ranges::sort(rk);
        rk.erase(unique(rk.begin(), rk.end()), rk.end());
        auto id = [&](int v) {
            return ranges::lower_bound(rk.begin(), rk.end(), v) - rk.begin() + 1;
        };
        vector<int> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            ans[i] = id(arr[i]);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [40,10,20,30]\n
// @lcpr case=end

// @lcpr case=start
// [100,100,100]\n
// @lcpr case=end

// @lcpr case=start
// [37,12,28,9,100,56,80,5,12]\n
// @lcpr case=end

 */

