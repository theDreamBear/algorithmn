/*
 * @lc app=leetcode.cn id=面试题 16.11 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 16.11] 跳水板
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
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k <= 0) return {};
        if (shorter == longer) return {shorter * k};
        int diff = longer - shorter;
        vector<int> ans;
        int total = shorter * k;
        for (int i = 0; i <= k; i++) {
           ans.push_back(total + i * diff);
        }
        ranges::sort(ans);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

 */

