/*
 * @lc app=leetcode.cn id=面试题 16.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.06] 最小差
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
    int smallestDifference(vector<int>& a, vector<int>& b) {
        ranges::sort(b);
        // 正 减 负 可能会溢出
        long long ans = LLONG_MAX;
        // 二分查找
        for (int i = 0; i < a.size(); i++) {
            auto it = ranges::upper_bound(b, a[i]);
            if (it != b.end()) {
                ans = min(ans, abs(apply))
            }
        }
    }
};
// @lc code=end



/*
// @lcpr case=start
// {1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}\n
// @lcpr case=end

 */

