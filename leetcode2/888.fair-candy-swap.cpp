/*
 * @lc app=leetcode.cn id=888 lang=cpp
 * @lcpr version=30204
 *
 * [888] 公平的糖果交换
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
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int t1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int t2 = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int ave = (t1 + t2) / 2;
        int need = (ave - t1);
        unordered_set<int> bb;
        for (auto v: bobSizes) bb.insert(v);
        for (auto v: aliceSizes) {
            if (bb.contains(v + need)) {
                return {v, v + need};
            }
        }
        return {0, 0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1]\n[2,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n[1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,5]\n[2,4]\n
// @lcpr case=end

 */

